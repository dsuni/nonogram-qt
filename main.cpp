/*
	nonogram-qt version 1.0.0, released 29 Jun 2013

	Copyright 2012, 2013 Daniel Suni

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QTranslator translator;
	translator.load(":/translations/nonogram_" + QLocale::system().name());
	app.installTranslator(&translator);
	app.setWindowIcon(QIcon(":/icon.png"));
	MainWindow mw;
	mw.show();
	return app.exec();
}
