/*
*
* OpenGL hardware capability viewer and database
*
* Main window class
*
* Copyright (C) 2011-2015 by Sascha Willems (www.saschawillems.de)
*
* This code is free software, you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License version 3 as published by the Free Software Foundation.
*
* Please review the following information to ensure the GNU Lesser
* General Public License version 3 requirements will be met:
* http://opensource.org/licenses/lgpl-3.0.html
*
* The code is distributed WITHOUT ANY WARRANTY; without even the
* implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE.  See the GNU LGPL 3.0 for more details.
*
*/

#ifndef GLCAPSVIEWER_H
#define GLCAPSVIEWER_H

#include <QtWidgets/QMainWindow>
#include <QNetworkReply>
#include "ui_glcapsviewer.h"
#include "glCapsViewerCore.h"
#include "settings.h"

class glCapsViewer : public QMainWindow
{
	Q_OBJECT

public:
	glCapsViewer(QWidget *parent = 0);
	~glCapsViewer();
	Ui::glcapsviewerClass ui;
	glCapsViewerCore core;
	GLFWwindow* window;
	void updateReportState();
	void generateReport();
	bool contextTypeSelection();
private:
	QNetworkAccessManager* nam;
	capsViewer::settings appSettings;
	bool canUpdateReport(int reportId);
	void refreshDeviceList();
	void generateInternalFormatInfo();
private slots:
	void slotRefreshReport();
	void slotClose();
	void slotExportXml();
	void slotBrowseDatabase();
	void slotShowDeviceOnline();
	void slotAbout();
	void slotSettings();
	void slotUpload();
	void slotRefreshDatabase();
	void slotDatabaseDevicesItemChanged();
	void slotDeviceVersionChanged(int index);
	void slotTabChanged(int index);
};

#endif // GLCAPSVIEWER_H
;