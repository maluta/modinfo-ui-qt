/*
  qmodinfo.cpp 
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


#include "qmodinfo.h"

#include <QProcess>
#include <QApplication>

#include "ui_tela.h"


QModInfo::QModInfo(QWidget *parent) : QWidget(parent){

	ui.setupUi(this);
	connect( ui.comboBox , SIGNAL(currentIndexChanged(int)) , this, SLOT(showModule(int)) );
	scan();		
	
}

QModInfo::~QModInfo() {

}

bool QModInfo::showModule(int index) {

     QProcess modinfo;
     modinfo.start("modinfo", QStringList() << ui.comboBox->itemText(index));
     if (!modinfo.waitForStarted())
         return false;

     if (!modinfo.waitForFinished())
         return false;

     QByteArray result = modinfo.readAll();
     ui.textEdit->setText(result);

     return true;
}

void QModInfo::scan() {
 

     QFile file("/proc/modules");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;

     QTextStream in(&file);
     QString line = in.readLine();
     while (!line.isNull()) {
	 modules << line.split(" ")[0];
         line = in.readLine();
     }

    modules.sort();
    ui.comboBox->insertItems(0,modules); 
    ui.label->setText("Total: " + QString::number(modules.size()));    

}

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QModInfo qmodinfo;
     qmodinfo.show();
     return app.exec();
 }
