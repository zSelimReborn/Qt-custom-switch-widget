//
// Created by Raffaele Montella on 18/09/21.
//

#ifndef QCSWITCHWIDGET_HPP
#define QCSWITCHWIDGET_HPP

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QObject>
#include <QRectF>
#include <QtMath>
#include <QPropertyAnimation>
#include <QAbstractButton>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPushButton>
#include <QLabel>



#if defined(UNIQUE_QCSWITCH_COMPILE_LIBRARY)
#  define UNIQUE_QCSWITCH_DECL  Q_DECL_EXPORT
#elif defined(UNIQUE_QCSWITCH_USE_LIBRARY)
#  define UNIQUE_QCSWITCH_DECL Q_DECL_IMPORT
#else
#  define UNIQUE_QCSWITCH_DECL
#endif

/* class QCSWITCH_DECL QcSwitchWidget;
class QCSWITCH_DECL ToggleBackground;
class QCSWITCH_DECL ToggleCircle;
class QCSWITCH_DECL ToggleButton;
class QCSWITCH_DECL SwitchButton; */

class UNIQUE_QCSWITCH_DECL QcSwitchWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QcSwitchWidget(QWidget *parent = 0);

    void setDrawBezel(bool drawBezel);
    bool getDrawBezel();

    void setTextPosition(int textPosition);
    int getTextPosition() const;

    void setTextPen(QPen pen);
    QPen getTextPen();

    void setTextFont(QFont font);
    QFont getTextFont();

    void setBazelPen(QPen pen);
    QPen getBazelPen();

    void setTrueFilename(QString trueFilename);
    QString getTrueFilename();

    void setFalseFilename(QString falseFilename);
    QString getFalseFilename();

    void setBazelRadius(int bazelRadius);
    int getBazelRadius() const;

    void setLabel(QString label);
    QString getLabel();

    void setState(bool state);
    bool getState() const;

Q_SIGNALS:
    void clicked();
    void released();
    void pressed();

public slots:

private:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *);

private:
    bool mDrawBezel;

    int mTextPosition;

    bool mState;
    QString mLabel;
    int mBazelRadius;
    QString mTrueFilename;
    QString mFalseFilename;

    QPen mTextPen;
    QPen mBazelPen;
    QFont mTextFont;
    int mXBackgroundOffset;
    int mYBackgroundOffset;

    void drawBezel(bool drawBezel);
};

class UNIQUE_QCSWITCH_DECL ToggleBackground : public QWidget
{
    Q_OBJECT
public:
    explicit ToggleBackground(QWidget* parent = nullptr, QColor color = Qt::white, bool rect = false);
    ~ToggleBackground() override;
    void paintEvent(QPaintEvent* event) override;

private:
    bool            _rect;
    int             _borderradius;
    QColor          _pencolor;
};

class UNIQUE_QCSWITCH_DECL ToggleCircle : public QWidget
{
    Q_OBJECT
public:
    explicit ToggleCircle(QWidget* parent = nullptr, QColor color = QColor(255, 255, 255), bool rect = false);
    ~ToggleCircle() override;
    void paintEvent(QPaintEvent* event) override;

private:
    bool            _rect;
    int             _borderradius;
    QColor          _color;
    QColor          _pencolor;
    QRadialGradient _radGradient;
    QLinearGradient _gradient;
};

class UNIQUE_QCSWITCH_DECL ToggleButton : public QWidget
{
    Q_OBJECT
public:
    enum Style
    {
        YESNO,
        ONOFF,
        TRUEFALSE,
        EMPTY
    };

public:
    ToggleButton(QWidget *parent = nullptr, Style style = Style::ONOFF, bool startValue = false, QColor color = Qt::white);
    ~ToggleButton();

    void mousePressEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent* event) override;
    void setValue(bool);
    bool value() const;
Q_SIGNALS:
    void onClick(bool status);

private:
    bool _value;
    int  _duration;

    QLinearGradient _gradient1;
    //QLinearGradient _gradient2;

    QColor _pencolor;
    QColor _offcolor;
    QColor _oncolor;

    QLabel*           _labeloff;
    ToggleBackground* _background;
    QLabel*           _labelon;
    ToggleCircle*     _circle;

    QPropertyAnimation* __btn_move;
    QPropertyAnimation* __back_move;
    void _update();
};

UNIQUE_QCSWITCH_DECL void setStylesheet(QWidget*, QString );

class UNIQUE_QCSWITCH_DECL SwitchButton : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget* parent = nullptr);
    ~SwitchButton();
    void setIcons(QString iconCheckPath, QString iconUncheckPath);
    QLabel* addLabel(float);
    void setStatus(bool checked);
Q_SIGNALS:
    void onClick(bool status);
private:
    QString _iconCheck;
    QString _iconUncheck;
    QPushButton* _pushButton= nullptr;
};

#endif //QCSWITCHWIDGET_HPP
