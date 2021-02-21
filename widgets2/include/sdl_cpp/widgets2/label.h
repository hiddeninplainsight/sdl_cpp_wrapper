#ifndef SDL_CPP_WRAPPER_LABEL_H
#define SDL_CPP_WRAPPER_LABEL_H

#include <sdl_cpp/widgets2/widget.h>
#include <sdl_cpp/texture.h>
#include <memory>

namespace sdl
{
	namespace widgets2
	{
		class label : public widget
		{
		private:
			std::unique_ptr<sdl::texture> texture_ptr;

			void update_texture();
			void recreate_texture();
		protected:
			void set_renderer(sdl::renderer *r) override;
		public:
			void draw() override;
			bool dimensions(int width, int height) override;
		};
	}
}

#endif	// SDL_CPP_WRAPPER_LABEL_H
