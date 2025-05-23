#include "framework.h"





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


   bool region::translate(const POINT& point, ::draw2d::graphics * pgraphics)
   {

      return true;

   }


   bool region::get_bounding_box(RECT * prectangle, ::draw2d::graphics * pgraphics)
   {

      defer_update(pgraphics, 0);

      Gdiplus::Rect int_rectangle;

      m_pregion->GetBounds(&rectangle, __graphics(pgraphics)->m_pgraphics);

      prectangle->left() = rectangle.X;

      prectangle->top() = rectangle.Y;

      prectangle->right() = rectangle.X + rectangle.Width;

      prectangle->bottom() = rectangle.Y + rectangle.Height;


      return true;

   }



   void region::expand_bounding_box(::double_rectangle * prectangle, ::draw2d::graphics * pgraphics)
   {

      ::int_rectangle rectangle;
      ((region*)this)->get_bounding_box(rectangle);
      copy(prectangle, &rectangle);

   }


   bool region::contains(const POINT & point, ::draw2d::graphics * pgraphics)
   {

      defer_update(pgraphics, 0);

      if (!m_pregion)
      {

         return ::draw2d::region::contains(point, pgraphics);

      }

      Gdiplus::PointF float_point((Gdiplus::REAL) point.x, (Gdiplus::REAL) point.y);

      return m_pregion->IsVisible(float_point)  != false;

   }


   bool region::create(::draw2d::graphics * pgraphics, char iCreate)
   {

      m_pregion = get(pgraphics);

      m_osdata[0] = m_pregion;

      return m_pregion != nullptr;

   }


   void region::destroy()
   {

      ::acme::del(m_pregion);

      ::draw2d::region::destroy();

   }


   Gdiplus::Region * region::get(::draw2d::graphics * pgraphics)
   {

      switch(m_eregion)
      {
      case ::draw2d::e_region_none:
         return normal_new Gdiplus::Region();
      case ::draw2d::e_region_rect:
         return get_rect(pgraphics);
      case ::draw2d::e_region_oval:
         return get_oval(pgraphics);
      case ::draw2d::e_region_polygon:
         return get_polygon(pgraphics);
      case ::draw2d::e_region_poly_polygon:
         return get_polygon(pgraphics);
      case ::draw2d::e_region_combine:
         return get_combine(pgraphics);
      default:
         ::exception::throw_not_implemented();
      }

      return nullptr;

   }

   Gdiplus::Region * region::get_rect(::draw2d::graphics * pgraphics)
   {

      Gdiplus::GraphicsPath path;

      Gdiplus::RectF int_rectangle;

      rectangle.X      = (Gdiplus::REAL) m_x1;
      rectangle.Y      = (Gdiplus::REAL) m_y1;
      rectangle.Width  = (Gdiplus::REAL) (m_x2 - m_x1);
      rectangle.Height = (Gdiplus::REAL) (m_y2 - m_y1);

      path.AddRectangle(rectangle);

      return normal_new Gdiplus::Region(&path);

   }


   Gdiplus::Region * region::get_oval(::draw2d::graphics * pgraphics)
   {

      Gdiplus::GraphicsPath path;

      path.AddEllipse((INT) m_x1, (INT) m_y1, (INT) (m_x2 - m_x1), (INT) (m_y2 - m_y1));

      return normal_new Gdiplus::Region(&path);

   }


   Gdiplus::Region * region::get_polygon(::draw2d::graphics * pgraphics)
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


   Gdiplus::Region * region::get_poly_polygon(::draw2d::graphics * pgraphics)
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


   Gdiplus::Region * region::get_combine(::draw2d::graphics * pgraphics)
   {

      if (!m_pregion1 || !m_pregion2)
      {

         return nullptr;

      }

      Gdiplus::Region * pregion = m_pregion1->get_os_data < Gdiplus::Region *>(pgraphics)->Clone();

      Gdiplus::Region * pregionOp = m_pregion2->get_os_data < Gdiplus::Region *>(pgraphics);

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



