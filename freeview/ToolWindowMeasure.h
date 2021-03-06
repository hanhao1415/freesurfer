/**
 * @file  ToolWindowMeasure.h
 * @brief REPLACE_WITH_ONE_LINE_SHORT_DESCRIPTION
 *
 */
/*
 * Original Author: Ruopeng Wang
 * CVS Revision Info:
 *    $Author: nicks $
 *    $Date: 2011/03/14 23:44:48 $
 *    $Revision: 1.15 $
 *
 * Copyright © 2011 The General Hospital Corporation (Boston, MA) "MGH"
 *
 * Terms and conditions for use, reproduction, distribution and contribution
 * are found in the 'FreeSurfer Software License Agreement' contained
 * in the file 'LICENSE' found in the FreeSurfer distribution, and here:
 *
 * https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferSoftwareLicense
 *
 * Reporting: freesurfer@nmr.mgh.harvard.edu
 *
 */
#ifndef TOOLWINDOWMEASURE_H
#define TOOLWINDOWMEASURE_H

#include "UIUpdateHelper.h"
#include <QWidget>
#include <QList>

namespace Ui
{
class ToolWindowMeasure;
}

class Region2D;
class SurfaceRegion;

class ToolWindowMeasure : public QWidget, public UIUpdateHelper
{
  Q_OBJECT

public:
  explicit ToolWindowMeasure(QWidget *parent = 0);
  ~ToolWindowMeasure();

  QString GetLabelStats();

public slots:
  void SetRegion(Region2D* reg = 0);
  void SetSurfaceRegion( SurfaceRegion* reg = 0 );

protected slots:
  void OnIdle();
  void OnAction(QAction* act);
  void UpdateWidgets();

  void OnLoad();
  void OnSave();
  void OnSaveAll();
  void OnUpdate();
  void OnCopy();
  void OnExport();
  void OnSpinBoxId(int val);
  void OnSpinBoxGroup(int val);
  void OnColorGroup( const QColor& color );

protected:
  virtual void showEvent(QShowEvent *);

private:
  Ui::ToolWindowMeasure *ui;

  QList<QWidget*> m_widgets2D;
  QList<QWidget*> m_widgets3D;
  Region2D*       m_region;
  SurfaceRegion*  m_surfaceRegion;
  bool            m_bToUpdateWidgets;
};

#endif // TOOLWINDOWMEASURE_H
