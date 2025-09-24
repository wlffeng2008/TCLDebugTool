#include "MainWindow.h"
#include "LogToFile.h"

#include <QDebug>
#include <QApplication>
#include <QLibraryInfo>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication::setStyle("Fusion");
    a.setStyleSheet(
    R"(
        QTableView{ border: 1px solid gray; gridline-color: transparent;  background-color: rgb(226, 249, 255) !important; gridline-color: gray;}
        QTableView::Item{padding-left:2px;  border-top: 0px solid gray; border-bottom: 1px solid transparent;border-right: 0px solid gray;}
        QTableView::Item::selected{ background-color: #a0bb9e !important; color:white; }
        QTableView QTableCornerButton::section { background-color: skyblue ; min-width: 32px; border-top: 0px solid gray; border-bottom: 1px solid gray; border-left: 0px solid gray; border-right: 1px solid gray; }

        QTableView QHeaderView::section{background-color:skyblue;}
        QTableView QHeaderView{background-color:skyblue;}
        QHeaderView::section:horizontal{  padding-left: 2px; border-top: 0px solid gray; border-bottom: 1px solid gray; border-right: 1px solid gray; font-weight: bold;}
        QHeaderView::section:vertical{  padding-left: 2px; min-width: 36px; border-top: 0px solid gray; border-bottom: 1px solid gray; border-left: 0px solid gray; border-right: 1px solid gray;}
        QTableView::indicator { width: 18px; height: 18px; }
        QTableView::indicator:checked { image: url(:/images/BoxChecked.png); }
        QTableView::indicator:unchecked { image: url(:/images/BoxUncheck.png); }
        QHeaderView::section:vertical{ text-align: right;}

        QLineEdit {border: 1px solid gray; border-radius: 4px; }
        QLineEdit:focus{ border: 1px solid #50b7c1; border-radius: 4px;  background-color: rgb(230, 240, 255);}

        QTextEdit {border: 1px solid gray; border-radius: 0px; }
        QTextEdit:focus{ border: 1px solid #50b7c1; border-radius: 4px; background-color: rgb(230, 240, 255);}

        QSlider::groove:horizontal { height: 8px; background: #DCDCDC; border-radius: 4px;}
        QSlider::sub-page:horizontal { background: #3EA8FF;  border-radius: 4px;}
        QSlider::handle:horizontal {
            width: 16px;
            height: 16px;
            margin: -6px 0;
            background: white;
            border: 2px solid #3EA8FF;
            border-radius: 9px; }

        QSlider::groove:vertical { width: 8px; background: #3EA8FF;  border-radius: 4px; }
        QSlider::sub-page:vertical { background: #DCDCDC;  border-radius: 4px; }
        QSlider::handle:vertical {
            width: 16px;
            height: 16px;
            margin: 0 -6px;
            background: white;
            border: 2px solid #3EA8FF;
            border-radius: 9px; }

        QSlider::handle:hover { background: #F0F0F0;}
        QSlider::handle:pressed { background: #E0E0E0; border-color: #2D7FDD; }

        QPushButton {
                background-color: #6C9F50;
                border-radius: 8px;
                color: white;
                border: 2px solid gray;
                padding: 2px 2px;
                min-width: 60px;
                min-height: 16px; }

        QPushButton:hover { background-color: #87ceeb; }
        QPushButton:pressed { background-color: #1e90af;}
        QPushButton:checked { background-color: #1e90ff;}
        QPushButton:disabled { background-color: gray; color: #cccccc;}

        QMessageBox {min-width: 500px; min-height: 250px;}
        QMessageBox QLabel#qt_msgbox_label{min-width: 450px; min-height: 120px; max-width: 450px; max-height: 520px; qproperty-alignment: AlignLeft; white-space: pre-wrap;font: bold 12px 微软雅黑;}
        QMessageBox QLabel#qt_msgboxex_icon_label{ min-width: 32px; min-height: 32px; max-width: 32px; max-height: 32px;qproperty-alignment: AlignTop;}
        QMessageBox QPushButton { /*background-color: #303CCF; border-radius: 4px; color:white;*/ min-width: 80px;min-height: 24px;}

        /* 文本和指示器间距 */
        QRadioButton { spacing: 5px; color: #333333; }
        QRadioButton::indicator {
            width: 14px;
            height: 14px;
            border: 2px solid #999999;
            border-radius: 8px;
        }

        QRadioButton::indicator:unchecked { background: #ffffff; }
        QRadioButton::indicator:unchecked:hover { border-color: #666666; background: #f0f0f0; }

        QRadioButton::indicator:checked {
            border: 2px solid #0085FF;
            background: qradialgradient(
                cx:0.5, cy:0.5, radius:0.4,
                fx:0.5, fy:0.5,
                stop:0 #0085FF, stop:1 white
            );
            color: #0085FF;
        }

        QRadioButton::indicator:checked:hover {
            border-color: #0066CC;
            background: qradialgradient(
                cx:0.5, cy:0.5, radius:0.4,
                fx:0.5, fy:0.5,
                stop:0 #0066CC, stop:1 white
            );
        }

        QRadioButton::indicator:pressed { border-color: #004499; }
        QRadioButton:disabled { color: #cccccc; }
        QRadioButton:checked {  color: #0085FF; }
        QRadioButton::indicator:disabled { border: 2px solid #dddddd; background: white; }


        QCheckBox { spacing: 5px; color: #333; }
        QCheckBox::indicator { width: 14px; height: 14px; }
        QCheckBox::indicator:unchecked { background: white; border: 2px solid #999; }
        QCheckBox::indicator:checked {
            width: 18px;
            height: 18px;
            background: transparent;
            image: url(:/images/BoxChecked.png);
        }

        QCheckBox::indicator:hover { border-color: #666; }
        QCheckBox:disabled { color: #AAA; }
        QCheckBox::indicator:disabled { background: #EEE; }

        QComboBox {
            border: 1px solid gray;
            border-radius: 4px;
            background: #FFFFFF;
            color: #333333;
            font-weight: normal;
            padding: 2px 2px;
        }

        QComboBox:hover { border-color: #ADADFD; }

        QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 18px;
            border-left: 1px solid #E0E0E0;
        }

        QComboBox::down-arrow { width: 14px; height: 14px; image: url(:/images/down-arrow.png); }
        QComboBox:disabled { background: #F5F5F5; color: #9E9E9E; }
        QComboBox:disabled::down-arrow { opacity: 0.5; }

        QSpinBox {border: 1px solid gray; border-radius: 4px; }
        QSpinBox:focus{ border: 1px solid #50b7c1; border-radius: 4px;  background-color: rgb(226, 249, 255);}

        QGroupBox * { font-size: 12px; font-weight: bold; }

    )");


/*QGroupBox{
background-color: #3EA8FF;
border-radius:4px ;
padding 3px ;
}
            QScrollBar:vertical { width: 14px;  }
            QScrollBar:vertical:hover {width: 14px;}
            background-color: #2E3648;
            color: #BDC8E2;
            border: 1px solid #414b60;

            QScrollBar:vertical {
                border: none;
                background: rgba(255, 255, 255, 0.1);
                width: 8px;
                margin: 2px 0 2px 0;
                border-radius: 3px;
            }

            QScrollBar::handle:vertical {
                background: rgba(128, 128, 128, 0.5);
                min-height: 20px;
                border-radius: 3px;
            }

            QScrollBar::handle:vertical:hover {
                background: rgba(96, 96, 96, 0.7);
            }

    // #MainWindow{background-image: url(:/images/bg.png) 0 0 0 0 stretch stretch;}
    // QTableView::indicator:unchecked { border: 0px solid #888; background-color: #fff; }

*/
    //tcl_log::LogInit() ;

    QApplication::setHighDpiScaleFactorRoundingPolicy(
        Qt::HighDpiScaleFactorRoundingPolicy::PassThrough  // 允许非整数倍缩放
    );

    QLocale::setDefault(QLocale(QLocale::Chinese,QLocale::China)) ;
    QTranslator translator ;
    bool bLoad = translator.load("qt_zh_TW.qm", QLibraryInfo::location(QLibraryInfo::TranslationsPath)) ;
    if(bLoad)
    {
        qDebug() << "installTranslator";
        a.installTranslator(&translator) ;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
