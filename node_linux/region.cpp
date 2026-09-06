#include "platform.h"





namespace draw2d_gdiplus
{


   region::region()
   {

      m_pthis = this;
      m_pregion = nullptr;

   }


   region::~region()
   {

      destroy();

   }


   bool region::translate(const POINT& point, ::draw2d::graphics * pdraw2dgraphics)
   {

      return true;

   }


   bool region::get_bounding_box(RECT * prectangle, ::draw2d::graphics * pdraw2dgraphics)
   {

      defer_update(pdraw2dgraphics, 0);

      Gdiplus::Rect i32_rectangle;

      m_pregion->GetBounds(&rectangle, __graphics(pdraw2dgraphics)->m_pgraphics);

      prectangle->left = rectangle.X;

      prectangle->top = rectangle.Y;

      prectangle->right = rectangle.X + rectangle.Width;

      prectangle->bottom = rectangle.Y + rectangle.Height;


      return true;

   }



   void region::expand_bounding_box(::f64_rectangle * prectangle, ::draw2d::graphics * pdraw2dgraphics)
   {

      ::i32_rectangle rectangle;
      ((region*)this)->get_bounding_box(rectangle);
      copy(prectangle, &rectangle);

   }


   bool region::contains(const POINT & point, ::draw2d::graphics * pdraw2dgraphics)
   {

      defer_update(pdraw2dgraphics, 0);

      if (!m_pregion)
      {

         return ::draw2d::region::contains(point, pdraw2dgraphics);

      }

      Gdiplus::PointF float_point((Gdiplus::REAL) point.x, (Gdiplus::REAL) point.y);

      return m_pregion->IsVisible(float_point)  != false;

   }


   bool region::create(::draw2d::graphics * pdraw2dgraphics, char iCreate)
   {

      m_pregion = get(pdraw2dgraphics);

      m_osdata[0] = m_pregion;

      return m_pregion != nullptr;

   }


   void region::destroy()
   {

      ::acme::del(m_pregion);

      ::draw2d::region::destroy();

   }


   Gdiplus::Region * region::get(::draw2d::graphics * pdraw2dgraphics)
   {

      switch(m_eregion)
      {
      case ::draw2d::e_region_none:
         return normal_new Gdiplus::Region();
      case ::draw2d::e_region_rect:
         return get_rect(pdraw2dgraphics);
      case ::draw2d::e_region_oval:
         return get_oval(pdraw2dgraphics);
      case ::draw2d::e_region_polygon:
         return get_polygon(pdraw2dgraphics);
      case ::draw2d::e_region_poly_polygon:
         return get_polygon(pdraw2dgraphics);
      case ::draw2d::e_region_combine:
         return get_combine(pdraw2dgraphics);
      default:
         ::exception::throw_not_implemented();
      }

      return nullptr;

   }

   Gdiplus::Region * region::get_rect(::draw2d::graphics * pdraw2dgraphics)
   {

      Gdiplus::GraphicsPath path;

      Gdiplus::RectF i32_rectangle;

      rectangle.X      = (Gdiplus::REAL) m_x1;
      rectangle.Y      = (Gdiplus::REAL) m_y1;
      rectangle.Width  = (Gdiplus::REAL) (m_x2 - m_x1);
      rectangle.Height = (Gdiplus::REAL) (m_y2 - m_y1);

      path.AddRectangle(rectangle);

      return normal_new Gdiplus::Region(&path);

   }


   Gdiplus::Region * region::get_oval(::draw2d::graphics * pdraw2dgraphics)
   {

      Gdiplus::GraphicsPath path;

      path.AddEllipse((INT) m_x1, (INT) m_y1, (INT) (m_x2 - m_x1), (INT) (m_y2 - m_y1));

      return normal_new Gdiplus::Region(&path);

   }


   Gdiplus::Region * region::get_polygon(::draw2d::graphics * pdraw2dgraphics)
   {

      Gdiplus::GraphicsPath path;

      array < Gdiplus::PointF > pa;

      for(int i = 0; i < m_nCount; i++)
      {
         pa.add(Gdiplus::PointF((Gdiplus::REAL) m_lppoints[i].x, (Gdiplus::REAL) m_lppoints[i].y));
      }

      if(m_efillmode == ::draw2d::fill_mode_alternate)
      {
         path.SetFillMode(Gdiplus::FillModeAlternate);
      }
      else
      {
         path.SetFillMode(Gdiplus::FillModeWinding);
      }

      path.AddPolygon(pa.get_data(), (int) pa.get_count());

      return normal_new Gdiplus::Region(&path);

   }


   Gdiplus::Region * region::get_poly_polygon(::draw2d::graphics * pdraw2dgraphics)
   {

      Gdiplus::GraphicsPath path;

      array < Gdiplus::PointF > pa;

      if(m_efillmode == ::draw2d::fill_mode_alternate)
      {
         path.SetFillMode(Gdiplus::FillModeAlternate);
      }
      else
      {
         path.SetFillMode(Gdiplus::FillModeWinding);
      }

      int n = 0;

      for(int i = 0; i < m_nCount; i++)
      {
         int jCount = m_lppolycounts[i];
         pa.erase_all();
         for(int j = 0; j < jCount; j++)
         {
            pa.add(Gdiplus::PointF((Gdiplus::REAL) m_lppoints[n].x, (Gdiplus::REAL) m_lppoints[n].y));
            n++;
         }
         path.AddPolygon(pa.get_data(), (int) pa.get_count());
         path.CloseFigure();
      }

      return normal_new Gdiplus::Region(&path);

   }


   Gdiplus::Region * region::get_combine(::draw2d::graphics * pdraw2dgraphics)
   {

      if (!m_pregion1 || !m_pregion2)
      {

         return nullptr;

      }

      Gdiplus::Region * pregion = m_pregion1->get_os_data < Gdiplus::Region *>(pdraw2dgraphics)->Clone();

      Gdiplus::Region * pregionOp = m_pregion2->get_os_data < Gdiplus::Region *>(pdraw2dgraphics);

      if(m_ecombine == ::draw2d::e_combine_add)
      {
         pregion->Union(pregionOp);
      }
      else if(m_ecombine == ::draw2d::e_combine_exclude)
      {
         pregion->Exclude(pregionOp);
      }
      else if(m_ecombine == ::draw2d::e_combine_intersect)
      {
         pregion->Intersect(pregionOp);
      }
      else
      {
         pregion->Union(pregionOp);
      }

      return pregion;

   }


} // namespace draw2d_gdiplus



