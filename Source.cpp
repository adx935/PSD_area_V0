/* This is the simplest version of pulse discrimination of an incoming signal 
by the ratio between the total area of the pulse and the area of the tail.
The signal input is a series of double values from a file.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N = 1000;			// Number of data points
double signal[];		// Vector to read out the voltage of the signal,
						// where signal[i] is the onecurrently being analyzed
double s = 0;			// signal[i]
double sum = 0;			// Sum for average
double average = 0;		// Average of the base of the pulse
double prevSignal = 0;	// Previous voltage signal
double totalArea = 0;	// Total area of the pulse
double partialArea = 0;	// Partial area of the pulse (tail)
double Vmax;			// Peak of the pulse
double threshold = 4;	// Threshold to indicate when a peak is detected

FILE *filePointer;

double x;

double baseAverage()
{
	for (int i = 0; i <= 100; i++)
	{
		s = signal[i];
		sum += s;
	}
	average = sum / 100;

	return average;
}

double Normalize(double average)
{
	for (int i = 0; i < N; i++)
	{
		s = signal[i];

		if (s > threshold)
		{
			if (s > prevSignal) continue;
			else if (s <= prevSignal)
			{
				s = Vmax;
				break;
			}
		}
	}

	double signalNorm[N];	// Vector that contains the normalized signal

	for (int i = 0; i < N; i++)
	{
		s = signal[i];
		s = (s - average) / (Vmax - average);
		signalNorm[i] = s;
	}

	return signalNorm[];
}

double startInt(double s)
{


}

void main()
{

//	filePointer = fopen("test_file.txt", "r");


	for (int i = 0; i < N; i++)
	{
	//	fscanf = (filePointer, "%f\n", &signal[i]);

		s = signalNorm[i];

		if (s > threshold)
		{
			if (s > prevSignal) totalArea += s;

			
		}

		else continue;
		prevSignal = signalNorm[i];

	}

	//fclose(filePointer);

}