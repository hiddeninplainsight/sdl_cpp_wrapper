#include "freetype_cpp/bitmap_glyph.h"
#include "freetype_cpp/glyph.h"
#include "freetype_cpp/freetype_exception.h"
#include <utility>

namespace freetype_cpp
{
	bitmap_glyph::bitmap_glyph(std::shared_ptr<glyph> glyph_ptr)
		: glyph_ptr{move(glyph_ptr)}
		, bitmap_object{nullptr}
		, advance{this->glyph_ptr->glyph_object->advance}
	{
		FT_Glyph glyph = this->glyph_ptr->glyph_object;
		auto error = FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, nullptr, 0);
		if(error)
		{
			throw freetype_exception{};
		}
		bitmap_object = reinterpret_cast<FT_BitmapGlyph>(glyph);
	}

	bitmap_glyph::~bitmap_glyph()
	{
		if(bitmap_object)
		{
			FT_Done_Glyph(reinterpret_cast<FT_Glyph>(bitmap_object));
		}
	}

	void bitmap_glyph::draw(draw_glyph_callback& callback)
	{
		callback.draw_glyph(bitmap_object->bitmap, bitmap_object->left, bitmap_object->top, advance);
	}
}
