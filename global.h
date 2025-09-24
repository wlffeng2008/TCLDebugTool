#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QEvent>
#include <QPainter>
#include <QTableView>
#include <QAbstractButton>

#include <windows.h>

bool isKeyPressed(int virtualKey);

QVector<double> movingAverage(const QVector<double>& data, int windowSize);

class CornerButtonProxy : public QObject
{
public:
    CornerButtonProxy(QTableView *view = nullptr, const QString &text = "序号"){
        attach(view,text) ;
    }

    void attach(QTableView *view, const QString &text="序号")
    {
        if(view)
        {
            QAbstractButton *btn = view->findChild<QAbstractButton*>();
            if (btn)
            {
                btn->setText(text);
                btn->installEventFilter(this);
            }
        }
    }

    bool eventFilter(QObject *watched, QEvent *event) override
    {
        if (event->type() == QEvent::Paint)
        {
            QAbstractButton *btn = static_cast<QAbstractButton*>(watched);
            if(btn)
            {
                QStyleOptionHeader opt;
                opt.text = btn->text();
                opt.rect = btn->rect();
                opt.textAlignment = Qt::AlignCenter ;
                QPainter painter(btn);
                btn->style()->drawControl(QStyle::CE_Header, &opt, &painter, btn);
                return true;
            }
        }
        return false;
    }
};


#endif // GLOBAL_H
