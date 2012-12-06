#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QMessageBox>
#include <QGtkStyle>
#include <QSignalMapper>
#include <QString>
#include <vector>
#include "pushbutton.h"
#include "nonogram.h"

#define MIN_PUZZLE_SIZE 3
#define MAX_PUZZLE_SIZE 30
#define DEFAULT_PUZZLE_SIZE 10
#define UNKNOWN 2
#define DOT 1
#define SOLID 0

class MainWindow : public QMainWindow {
	Q_OBJECT

 private:
	QWidget *window;
	QMenuBar *menu;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QAction *exitAction;
	QAction *aboutAction;
	QAction *helpAction;
	QSpinBox *widthBox;
	QSpinBox *heightBox;
	QVBoxLayout *layout;
	QHBoxLayout *top;
	QGridLayout *grid;
	QGtkStyle *style;
	QLabel *widthLabel;
	QLabel *heightLabel;
	QPushButton *generate;
	QPushButton *surrender;
	QSignalMapper *mapperLeftButton;
	QSignalMapper *mapperRightButton;
	vector<PushButton*> puzzle;
	vector<QLabel*> x_axis, y_axis;
	vector<size_t> **x_axis_clue;
	vector<size_t> **y_axis_clue;
	vector<int> status;
	int width, height, mouseButton;
	bool firstClick, lockAction;
	nonogram *ngram;
	void cleanUp();

 public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

 private slots:
	void generatePuzzle();
	void giveUp();
	void solidClicked(int position);
	void dotClicked(int position);
	void checkSolution();
	void quit();
	void help();
	void about();
};
#endif
