#include "freetype_cpp/face.h"
#include "freetype_cpp/freetype_exception.h"
#include <utility>
#include "freetype_cpp/library.h"

using namespace std;

namespace freetype_cpp
{
	face::face(std::shared_ptr<library> library_ptr, char const* file_path,
			   FT_Long face_index)
		: library_ptr{move(library_ptr)}
	{
		FT_Error error = FT_New_Face(this->library_ptr->library_object,
									 file_path, face_index, &face_object);
		if (error)
		{
			throw freetype_exception{};
		}
	}

	face::face(std::shared_ptr<library> library_ptr, FT_Byte const* memory,
			   FT_Long memory_size, FT_Long face_index)
		: library_ptr{move(library_ptr)}
	{
		FT_Error error =
			FT_New_Memory_Face(this->library_ptr->library_object, memory,
							   memory_size, face_index, &face_object);
		if (error)
		{
			throw freetype_exception{};
		}
	}

	face::~face() { FT_Done_Face(face_object); }

	shared_ptr<face> face::initialise_from_file(
		std::shared_ptr<library> library_ptr, char const* file_path,
		FT_Long face_index)
	{
		return shared_ptr<face>(
			new face{move(library_ptr), file_path, face_index});
	}

	std::shared_ptr<face> face::initialise_from_memory(
		std::shared_ptr<library> library_ptr, FT_Byte const* memory,
		FT_Long memory_size, FT_Long face_index)
	{
		return shared_ptr<face>(
			new face{move(library_ptr), memory, memory_size, face_index});
	}

	void face::set_font_size(points size, FT_UInt horizontal_resolution,
							 FT_UInt vertical_resolution)
	{
		FT_Error error =
			FT_Set_Char_Size(face_object, 0, static_cast<FT_F26Dot6>(size),
							 horizontal_resolution, vertical_resolution);
		if (error)
		{
			throw freetype_exception{};
		}
	}

	bool face::draw_glyph(FT_ULong c, draw_glyph_callback& callback,
						  FT_Int32 load_flags)
	{
		auto error = FT_Load_Char(face_object, c, load_flags);
		if (error)
			return false;

		callback.draw_glyph(face_object->glyph);
		return true;
	}

	FT_Pos face::line_height() const
	{
		auto error = FT_Load_Char(face_object, 'T', FT_LOAD_RENDER);
		if (error)
		{
			throw freetype_exception{};
		}

		auto above_origin = face_object->glyph->metrics.horiBearingY;

		error = FT_Load_Char(face_object, 'g', FT_LOAD_RENDER);
		if (error)
		{
			throw freetype_exception{};
		}

		auto below_origin = face_object->glyph->metrics.height -
							face_object->glyph->metrics.horiBearingY;

		return above_origin + below_origin;
	}
}
