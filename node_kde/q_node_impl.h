//
// Created by camilo on 28/01/2021. 02:44 --<33ThomasBorregaardSoerensen!! My ONLY GOD!!
//
#pragma once


#include <qmetatype.h>
#include <QApplication>
#include <QPalette>
#include <QAbstractNativeEventFilter>

#include "node_impl.h"
#include "acme/user/os_theme_colors.h"




class q_node_impl :
   virtual public node_impl,
   virtual public QAbstractNativeEventFilter

{
public:


   QApplication m_qapplication;

   QPalette m_qpalette;


   q_node_impl(int argc, char ** ppsz);
   virtual ~q_node_impl();


   virtual os_theme_colors *  new_os_theme_colors() override;
   virtual void exec() override;

   virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);

};


