#include <iostream>
#include <ctime>
#include <random>

#include "Core.h"
#include "Image.h"

using namespace std;

float Max(float A, float B)
{
	return A >= B ? A : B;
}

float Min(float A, float B)
{
	return A <= B ? A : B;
}

float Clamp(float min, float max, float value)
{
	if (value >= max)
	{
		return max;
	}
	else if (value <= min)
	{
		return min;
	}
	else
	{
		return value;
	}
}

float Lerp(float min, float max, float alpha)
{
	alpha = Clamp(0.0, 1.0, alpha);

	if (min >= max)
	{
		return min;
	}
	else
	{
		float lenth = max - min;
		float addvalue = lenth * alpha;
		return min + addvalue;
	}
}

float remap(float V, float L0, float H0, float Ln, float Hn)
{
	return Ln + (V - L0) * (Hn - Ln) / (H0 - L0);
}

float smoothstep(float min, float max, float value)
{
	if (min >= max)
	{
		if (value <= min)
		{
			return 0.0f;
		}
		else if (value > max)
		{
			return 1.0f;
		}
	}

	if (value <= min)
	{
		return 0.0f;
	}
	else if (value >= max)
	{
		return 1.0f;
	}
	else
	{
		return remap(value, min, max, 0.0, 1.0);
	}
}

int main()
{
	FLinerColor ClearColor = FLinerColor(1, 1, 1, 1);

	FImage* OutputImage = new FImage(256, 256, "PreintegratedToonBRDF");
	OutputImage->ClearImage(ClearColor);

	vector<FLinerColor>* ColorData = new vector<FLinerColor>(256 * 256);
	vector<FLinerColor>& data = *ColorData;
	for (int y = 0; y < 256; y++)
	{
		for (int x = 0; x < 256; x++)
		{
			FLinerColor RetColor = FLinerColor(0, 0, 0, 0);
			float Y = (float)y / 256.0f;
			float X = (float)x / 256.0f;

			Y = Y * 0.1f;

			RetColor.R = smoothstep(0.5f - Y, 0.5 + Y, X);
			RetColor.G = smoothstep(0.5f - Y, 0.5 + Y, X);
			RetColor.B = smoothstep(0.5f - Y, 0.5 + Y, X);

			data[x + y * 256] = RetColor;
		}
	}

	OutputImage->DrawImageData(*ColorData);
	OutputImage->SaveImageToDesk("C:/Users/YivanLee/Desktop/");

	system("Pause");
	return 0;
}