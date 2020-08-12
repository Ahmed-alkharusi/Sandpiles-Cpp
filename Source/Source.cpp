#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <chrono>
/*
====================
 === Snadpiles ===
====================
Updated on Aug 8 2020
@author : Ahmed Al-kharusi

The "olcPixelGameEngine.h" is a single header file that enables us to draw graphics.
This is created by javidx9 (OneLoneCoder). I used this and the example template provided
in his repo to draw the sandpile matrix.
please download it from his repo
https://github.com/OneLoneCoder/olcPixelGameEngine

*/

void sandpile_matrix(std::vector<std::vector<int>>& matrix, size_t& max_iteration);


class Sandpile : public olc::PixelGameEngine
{
public:
	Sandpile()
	{
		sAppName = "Sandpile";
	}
	int resolution_height{ 1080 };
	int resolution_width{ 1920 };
	
	std::vector<std::vector<int>> matrix;
	int temp =1;
	size_t min = 0;
	size_t max = 0;
	size_t k = 0;
	int max_iteration = 1000000;
	std::vector<int> vec_colour_1{ 0, 0, 128 };
	std::vector<int> vec_colour_2{ 0, 0, 255 };
	std::vector<int> vec_colour_3{ 128, 0, 0 };
	std::vector<int> vec_colour_4{ 255, 255, 0 };

	

public:

	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		if (temp == 1) {
			Clear(olc::WHITE);
		}
		else if (temp == 2)
		{
			Clear(olc::RED);
		}
		else if (temp == 3)
		{
			Clear(olc::BLACK);
		}
		else if(temp == 4) {
			Clear(olc::BLUE);
		}
		
		if (GetKey(olc::Key::B).bHeld) {
			

			bool done = false;
			do {
			std::cout << " \n Please select a clour from the list:\n 1. WHITE \n 2. RED \n 3. BLACK \n 4. BLUE \n";
			std::cin >> temp;
			if (temp == 1 || temp == 2 || temp == 3 || temp == 4) {
				done = true;

			
			
			}
			} while (!done);
		}

		DrawLine(200,200, resolution_width - 900, 200, olc::BLACK);
		DrawLine(200, 200, 200, resolution_height - 200, olc::BLACK);
		DrawLine(200, resolution_height - 200, resolution_width - 900, resolution_height - 200, olc::BLACK);
		DrawLine(resolution_width - 900, resolution_height - 200, resolution_width - 900,200, olc::BLACK);
		for (size_t i{ 200 };i < resolution_height-200;i++) {

			for (size_t j{200 };j < resolution_width-900;j++) {
				if (matrix[i][j] > 3) {
					matrix[i][j] -= 4;
					matrix[i][j + 1] += 1;
					matrix[i][j - 1] += 1;
					matrix[i + 1][j] += 1;
					matrix[i - 1][j] += 1;
				}
			}
		}
		k += 1;

		for (int x = 100; x < ScreenWidth()-100; x++)
			for (int y = 100; y < ScreenHeight()-100; y++)
				if (matrix[y][x] == 1) {
					Draw(x, y, olc::Pixel(vec_colour_1[0], vec_colour_1[1], vec_colour_1[2]));
				}else if (matrix[y][x] == 2) {
					Draw(x, y, olc::Pixel(vec_colour_2[0], vec_colour_2[1], vec_colour_2[2]));
				}else if (matrix[y][x] == 3) {
					Draw(x, y, olc::Pixel(vec_colour_3[0], vec_colour_3[1], vec_colour_3[2]));
				}
				else if (matrix[y][x] == 4) {
					Draw(x, y, olc::Pixel(vec_colour_4[0], vec_colour_4[1], vec_colour_4[2]));
				}
		DrawString(ScreenWidth() - 700, 10, "Menu                         | Key (Hold) \n________________________________\n\nPress with your mouse at\n\nany point to start     \n\nChange Background colours     		  | B\n\nChange colours	------------------	| C\n\nAbout ----------------------------| A\n\n\n               This will display in a\n\n               separate window\n\n\n", olc::BLACK, 2);

		if (GetMouse(0).bHeld)
		{
			matrix[GetMouseY()][GetMouseX()] = max_iteration;
		}
		if (GetKey(olc::Key::A).bHeld) {
			std::cout << "\n\n=============================================================================\nSnadpiles \n========================================================================================\nUpdated on Aug 11 2020\n@author: Ahmed Alkharusi\nI used the olcPixelGameEngine to generate the graphics.\nThe olcPixelGameEngine.h is a single header file that enables us to draw graphics.\nThis is created by javidx9(OneLoneCoder).\nplease download it from his repo\nhttps ://github.com/OneLoneCoder/olcPixelGameEngine " << std::endl;
		}
		if (GetKey(olc::Key::C).bHeld)
		{
			bool done = false;
			do {
				std::cout << "\n See https://www.rapidtables.com/web/color/RGB_Color.html\n\nPlease enter the 1st RGB colour:\n THE VALUES MUST BE IN THE RANGE 0 - 255\ne.g. 255 255 0\n ";
				std::cin >> vec_colour_1[0] >> vec_colour_1[1] >> vec_colour_1[2];
				if (vec_colour_1[0] <= 255 && vec_colour_1[0] >= 0 && vec_colour_1[1] <= 255 && vec_colour_1[1] >= 0 && vec_colour_1[2] <= 255 && vec_colour_1[2] >= 0)
					done = true;
			} while (!done);
			done = false;
			do {
				std::cout << "\n Please enter the -----2nd---- RGB colour:\n THE VALUES MUST BE IN THE RANGE 0 - 255\ne.g. 255 255 0\n ";
				std::cin >> vec_colour_2[0] >> vec_colour_2[1] >> vec_colour_2[2];
				if (vec_colour_2[0] <= 255 && vec_colour_2[0] >= 0 && vec_colour_2[1] <= 255 && vec_colour_2[1] >= 0 && vec_colour_2[2] <= 255 && vec_colour_2[2] >= 0)
					done = true;
			} while (!done);
			done = false;
			do {
				std::cout << "\n Please enter the -----3rd----- RGB colour:\n THE VALUES MUST BE IN THE RANGE 0 - 255\ne.g. 255 255 0\n ";
				std::cin >> vec_colour_3[0] >> vec_colour_3[1] >> vec_colour_3[2];
				if (vec_colour_3[0] <= 255 && vec_colour_3[0] >= 0 && vec_colour_3[1] <= 255 && vec_colour_3[1] >= 0 && vec_colour_3[2] <= 255 && vec_colour_3[2] >= 0)
					done = true;
			} while (!done);


		}
				
		return true;
	}
};


int main()
{
	Sandpile demo;
	std::vector<std::vector<int>> matrix1(demo.resolution_height, std::vector<int>(demo.resolution_width, 0));
	demo.matrix = matrix1;

	if (demo.Construct( demo.resolution_width, demo.resolution_height, 1, 1))
		demo.Start();

	return 0;
}
void sandpile_matrix(std::vector<std::vector<int>>& matrix, size_t& max_iteration) {
	size_t mid_point = static_cast<size_t>((matrix.size() - 1) / 2);

	matrix[mid_point][mid_point] = static_cast<int>(1.2 * max_iteration);
	size_t min = 0;
	size_t max = 0;
	for (size_t k{ 0 };k < (max_iteration);k++) {
		if ((k + 1) < mid_point) {
			min = (mid_point - (k + 1));
			max = (mid_point + (k + 1));
		}
		else {
			min = 0;
			max = 2*mid_point ;
		}

		for (size_t i{ min };i < max;i++) {

			for (size_t j{ min };j < max;j++) {
				if (matrix[i][j] > 3) {
					matrix[i][j] -= 4;
					matrix[i][j + 1] += 1;
					matrix[i][j - 1] += 1;
					matrix[i + 1][j] += 1;
					matrix[i - 1][j] += 1;
				}
			}
		}
	}
}

