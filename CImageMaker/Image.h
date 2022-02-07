#pragma once

#include "Core.h"
#include <vector>
#include <string>

using namespace std;

class FImage
{
public:

	FImage(int X, int Y, string ImageName) :
		SizeX(X),
		SizeY(Y),
		ImageName(ImageName)
	{
		for (int i = 0; i < SizeX; i++)
		{
			vector<FColor> row(SizeY);
			Imagedata.push_back(row);
		}
	}

	bool SaveImageToDesk(const string& Path);
	void ClearImage(FLinerColor& ClearColor);
	void DrawImageData(const vector<FLinerColor>& ColorData);

	int SizeX;
	int SizeY;
	string ImageName;
	string ImagePath;
	vector<vector<FColor>> Imagedata;
};

class FRenderTarget
{

public:

	FRenderTarget(int size_X, int size_Y):
		SizeX(size_X),
		SizeY(size_Y)
	{
		ImageData.resize(SizeX * SizeY);
	}

	int SizeX;
	int SizeY;
	string RendertargetName;

	vector<FColor> ImageData;

	void DrawRenderTarget(const vector<FLinerColor>& ColorData);
};
