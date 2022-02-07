
#include "Image.h"
#include <fstream>
#include <iostream>

using namespace std;

void FImage::ClearImage(FLinerColor& ClearColor)
{
	cout << endl << "Begin clear image operation" << endl;

	int nx = Imagedata.size();
	int ny = Imagedata[0].size();

	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny; j++)
		{
			Imagedata[i][j] = ClearColor.LinerColorToFColor();
		}
	}
}

void FImage::DrawImageData(const vector<FLinerColor>& ColorData)
{
	//       0
	//       ________________\x
	//       |               /
	//       |
	//       |
	//       |
	//       |
	//    Y \/                

	int nx = Imagedata.size();
	int ny = Imagedata[0].size();

	if (ColorData.size() != nx * ny)
	{
		cout << endl << "Draw Color data failed because the color data size not equal to image data size" << endl;
	}

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			Imagedata[x][y] = ColorData[SizeY * y + x].LinerColorToFColor();
		}
	}
}

bool FImage::SaveImageToDesk(const string& Path)
{
	cout << endl << "begin save image to desk operation" << endl;

	bool bCreateImage = false;

	ofstream fout(Path + ImageName + ".ppm");
	fout << "P3\n" << SizeX << " " << SizeY << "\n255\n";

	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			FColor& color = Imagedata[x][y];

			fout << color.R << " " << color.G << " " << color.B << "\n";
		}
	}

	fout.close();

	cout << endl << "Save image successfully" << endl;

	return bCreateImage;
}

void FRenderTarget::DrawRenderTarget(const vector<FLinerColor>& ColorData)
{
	//       0
	//       ________________\x
	//       |               /
	//       |
	//       |
	//       |
	//       |
	//    Y \/                

	if (ColorData.size() != SizeX * SizeY)
	{
		cout << endl << "Draw Color data into render target failed becuse the color data size not equal to image data size" << endl;
	}

	for (int j = 0; j < SizeY; j++)
	{
		for (int i = 0; i < SizeX; i++)
		{
			ImageData[i + SizeY * j] = ColorData[SizeY * j + i].LinerColorToFColor();
		}
	}
}