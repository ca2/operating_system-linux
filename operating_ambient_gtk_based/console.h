#pragma once


#include "acme/operating_system/console.h"
//#include "acme/filesystem/file/text_stream.h"


namespace acme_linux
{


   class CLASS_DECL_ACME console :
      virtual public ::console::console
   {
   public:


      //__creatable_from_library(console, ::console::console, "acme_linux");


      void *                                       m_pscreen;
      void *                                       m_pwindow;
      ::pointer<stdio_file>                        m_pfileOut;
      ::pointer<stdio_file>                        m_pfileIn;
      int                                          m_iW;
      int                                          m_iH;
      int                                          m_iColor;


      console();
      ~console() override;

      //::write_text_stream < ::file::file > & cout() override;

      void redirect_io();
      void SetWindowSize(int height,int width);
      void SetCursorVisibility(bool show);
      void SetCursorPosition(int y,int x);
      void SetTextColor(int color);
      void SetScreenColor(enum_dos_color color, int iLineStart = 0, int iLineCount = -1);
      void write(const ::string & psz);

   };


} // namespace acme_linux




