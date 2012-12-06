#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMouseEvent>

#define SIZE 20

class PushButton : public QPushButton {
	Q_OBJECT

 private:
	int *button;
	bool *first;

 public:
	PushButton(int *b, bool *f, QWidget *parent = 0);
	
 protected:
	void dragEnterEvent(QDragEnterEvent *e);
	void mousePressEvent(QMouseEvent *e);

 signals:
	void solid();
	void dot();
};
#endif
