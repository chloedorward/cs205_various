#ifndef BEECHIMES_H
#define BEECHIMES_H

#include <vector>
#include <math.h>

#include <QWidget>
#include <QMediaPlayer>
#include <QTimer>

struct Event
{
    long time;
    int g1;
    int g2;
    int g3;
    int g4;
    int g5;
    int g6;
    int g7;
    int g8;
};

namespace Ui {
class BeeChimes;
}

class BeeChimes : public QWidget
{
    Q_OBJECT

public:
    explicit BeeChimes(QWidget *parent = nullptr, int id = 0);
    ~BeeChimes();

private slots:
    void play_events();
    void on_pb_play_clicked();

    void on_vs_volume_sliderMoved(int position);

    void on_pb_pause_clicked();

    void on_pb_stop_clicked();

    void on_pb_back_clicked();

private:
    Ui::BeeChimes *ui;// ui
    // vector of events
    std::vector<Event> events;
    // instance variables related to events
    int events_ind;
    // instance variables related to timer
    QTimer * timer; // timer
    int curr_time; // current time, in relation to start of timer
    int incr; // time increment of timer
    // instance variables related to QMediaPlayers
    int num_players; // size of qmp vectors
    int max_vol; // maximum volume
    double vol_adjust; // EXBLAINNNNN
    // QMediaPlayer * vectors for each gate
    std::vector<QMediaPlayer *> g1_qmps;
    std::vector<QMediaPlayer *> g2_qmps;
    std::vector<QMediaPlayer *> g3_qmps;
    std::vector<QMediaPlayer *> g4_qmps;
    std::vector<QMediaPlayer *> g5_qmps;
    std::vector<QMediaPlayer *> g6_qmps;
    std::vector<QMediaPlayer *> g7_qmps;
    std::vector<QMediaPlayer *> g8_qmps;
    // number of times each type of gate has been played
    // used for cycling through qmp objects in the appropriate vectors*/
    int g1_plays;
    int g2_plays;
    int g3_plays;
    int g4_plays;
    int g5_plays;
    int g6_plays;
    int g7_plays;
    int g8_plays;

    // methods for each gate's qmp vector
    void play_g1(int active);
    void play_g2(int active);
    void play_g3(int active);
    void play_g4(int active);
    void play_g5(int active);
    void play_g6(int active);
    void play_g7(int active);
    void play_g8(int active);
    void play_gates(int g1_a, int g2_a, int g3_a, int g4_a, int g5_a, int g6_a, int g7_a, int g8_a);
    void loadQMPs(); // creates new qmp objects in the appropriate vectors
    void loadEvents(); // loads in events to play

    int hiveID;
};

#endif // BEECHIMES_H
