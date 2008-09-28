/*
  qmodinfo.h 
  Copyright (C) 2008 - Tiago Maluta (maluta@unifei.edu.br)
 
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#ifndef QMODINFO_H
#define QMODINFO_H

#include <QString>
#include <QWidget>
#include <QFile>
#include <QStringList>
#include <QTextStream>

#include "ui_tela.h"

class QModInfo : public QWidget{

Q_OBJECT

public:
	QModInfo(QWidget *parent = 0);
	~QModInfo();

	void scan();

private:
	Ui::Form ui; 
	QStringList modules;

private slots:
	bool showModule(int);

		
};


#endif
