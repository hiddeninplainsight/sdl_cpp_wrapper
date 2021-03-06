#include "freetype_cpp/glyph.h"
#include "freetype_cpp/freetype_exception.h"
#include "freetype_cpp/face.h"
#include <utility>

using namespace std;

namespace freetype_cpp
{
	glyph::glyph(std::shared_ptr<face> face_ptr)
		: face_ptr{move(face_ptr)}
	{
	}

	glyph::~glyph()
	{
		if(glyph_object)
		{
			FT_Done_Glyph(glyph_object);
		}
	}

	std::shared_ptr<glyph> glyph::initialise_from_face(
		std::shared_ptr<face> face_ptr, FT_ULong c)
	{
		auto g = shared_ptr<glyph>{new glyph{move(face_ptr)}};
		g->face_ptr->get_glyph(c, *g, FT_LOAD_NO_BITMAP);
		return g;
	}

	void glyph::receive_glyph(const FT_GlyphSlot &glyph)
	{
		auto error = FT_Get_Glyph(glyph, &glyph_object);
		if(error)
		{
			throw freetype_exception{};
		}
	}
}
