#pragma once


namespace linux
{


   class CLASS_DECL_ACME console :
      virtual public ::console::console
   {
   public:


      void *                  m_pscreen;
      void *                  m_pwindow;
      ::string_stream         m_cout;
      __pointer(stdio_file)   m_pfileOut;
      __pointer(stdio_file)   m_pfileIn;
      int                     m_iW;
      int                     m_iH;
      int                     m_iColor;


      console();
      ~console() override;

      ::string_stream & cout() override;

      void redirect_io();
      void SetWindowSize(int height,int width);
      void SetCursorVisibility(bool show);
      void SetCursorPosition(int y,int x);
      void SetTextColor(int color);
      void SetScreenColor(enum_dos_color color, int iLineStart = 0, int iLineCount = -1);
      void write(const ::string & psz);

   };


} // namespace windows




