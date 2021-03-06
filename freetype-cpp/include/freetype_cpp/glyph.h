#ifndef FREETYPE_CPP_FREETYPE_GLYPH_H
#define FREETYPE_CPP_FREETYPE_GLYPH_H

#include "get_glyph_callback.h"

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include <memory>

namespace freetype_cpp
{
	class face;
	class bitmap_glyph;

	class glyph : private get_glyph_callback
	{
	public:
		friend class bitmap_glyph;

	private:
		std::shared_ptr<face> face_ptr;
		FT_Glyph glyph_object{nullptr};

		explicit glyph(std::shared_ptr<face> face_ptr);

	public:
		~glyph() override;

		glyph(glyph const&) = delete;
		glyph& operator=(glyph const&) = delete;

		static std::shared_ptr<glyph> initialise_from_face(
			std::shared_ptr<face> face_ptr, FT_ULong c);

	private:
		void receive_glyph(FT_GlyphSlot const& glyph) override;
	};
}

#endif	// FREETYPE_CPP_FREETYPE_GLYPH_H
