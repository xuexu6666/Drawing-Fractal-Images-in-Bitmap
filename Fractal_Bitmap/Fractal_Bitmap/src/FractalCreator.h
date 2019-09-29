#pragma once

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

namespace caveofprogramming {

	class FractalCreator {
	private:
		int m_width;
		int m_height;
		std::vector<int> m_histogram;
		std::vector<int> m_fractal;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{ 0 };

		std::vector<int> m_ranges;
		std::vector<RGB> m_colors;
		std::vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

	private:
		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(std::string name);
		int getRange(int iterations) const;

	public:
		FractalCreator(int width, int height);
		void addRange(double rangeEnd, const RGB& rgb);
		void addZoom(const Zoom& zoom);
		virtual ~FractalCreator();
		void run(std::string name);
	};
}