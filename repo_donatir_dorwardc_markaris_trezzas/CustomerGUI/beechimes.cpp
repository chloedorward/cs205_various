#include "beechimes.h"
#include "ui_beechimes.h"

BeeChimes::BeeChimes(QWidget *parent, int id) :
    QWidget(parent),
    ui(new Ui::BeeChimes)
{
    ui->setupUi(this);

    incr = 100;
    curr_time = 0;
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(play_events()));
    max_vol = 100;
    vol_adjust = 0.5;
    events_ind = 0;
    hiveID = id;

    g1_plays = 0;
    g2_plays = 0;
    g3_plays = 0;
    g4_plays = 0;
    g5_plays = 0;
    g6_plays = 0;
    g7_plays = 0;
    g8_plays = 0;
    num_players = 10;

    loadQMPs();
    loadEvents();
    QString title = "Welcome to Hive ";
    title += QString::number(hiveID);
    title += " BeeChimes";
    ui->l_title->setText(title);
}

BeeChimes::~BeeChimes()
{
    for(int i = 0; i < g1_qmps.size(); i++)
    {
        delete g1_qmps[i];
        delete g2_qmps[i];
        delete g3_qmps[i];
        delete g4_qmps[i];
        delete g5_qmps[i];
        delete g6_qmps[i];
        delete g7_qmps[i];
        delete g8_qmps[i];
    }
    delete timer;
    delete ui;
}

void BeeChimes::loadQMPs()
{
    for(int i = 0; i < num_players; i++)
    {
        g1_qmps.push_back(new QMediaPlayer());
        g1_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_c5.mp3"));
        g2_qmps.push_back(new QMediaPlayer());
        g2_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_e5.mp3"));
        g3_qmps.push_back(new QMediaPlayer());
        g3_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_g5.mp3"));
        g4_qmps.push_back(new QMediaPlayer());
        g4_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_b5.mp3"));
        g5_qmps.push_back(new QMediaPlayer());
        g5_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_b6.mp3"));
        g6_qmps.push_back(new QMediaPlayer());
        g6_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_g6.mp3"));
        g7_qmps.push_back(new QMediaPlayer());
        g7_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_e6.mp3"));
        g8_qmps.push_back(new QMediaPlayer());
        g8_qmps[i]->setMedia(QUrl("qrc:/sounds/bells_c6.mp3"));
    }
}

void BeeChimes::loadEvents()
{
    // currently hard coded
    // ADD FUNCTIONALITY
    Event one = {1000, 1, 0, 0, 0, 0, 0, 0, 0};
    Event two = {1500, 0, 1, 0, 0, 0, 0, 0, 0};
    Event three = {2000, 0, 0, 1, 0, 0, 0, 0, 0};
    Event four = {2500, 0, 0, 0, 1, 0, 0, 0, 0};
    Event five = {3000, 0, 0, 0, 0, 1, 0, 0, 0};
    Event six = {3500, 0, 0, 0, 0, 0, 1, 0, 0};
    Event seven = {4000, 0, 0, 0, 0, 0, 0, 1, 0};
    Event eight = {4500, 0, 0, 0, 0, 0, 0, 0, 1};
    //Event nine = {8003, 1, 0, 0, 0, 0, 0, 0, 0};
    //Event ten = {8004, 0, 1, 0, 0, 0, 0, 0, 0};
    events.push_back(one);
    events.push_back(two);
    events.push_back(three);
    events.push_back(four);
    events.push_back(five);
    events.push_back(six);
    events.push_back(seven);
    events.push_back(eight);
    //events.push_back(nine);
    //events.push_back(ten);
}

void BeeChimes::on_pb_play_clicked()
{
    timer->start(incr);
    ui->l_status->setText("Pressed Play");
}

void BeeChimes::play_events()
{
    if(events_ind >= events.size())
        return;
    int g1s = 0;
    int g2s = 0;
    int g3s = 0;
    int g4s = 0;
    int g5s = 0;
    int g6s = 0;
    int g7s = 0;
    int g8s = 0;
    while(events_ind < events.size() && events[events_ind].time > curr_time && events[events_ind].time <= (curr_time + incr))
    {
        g1s += events[events_ind].g1;
        g2s += events[events_ind].g2;
        g3s += events[events_ind].g3;
        g4s += events[events_ind].g4;
        g5s += events[events_ind].g5;
        g6s += events[events_ind].g6;
        g7s += events[events_ind].g7;
        g8s += events[events_ind].g8;
        events_ind++;
    }
    play_gates(g1s, g2s, g3s, g4s, g5s, g6s, g7s, g8s);
    curr_time += incr;
    if(events_ind >= events.size())
    {
        timer->stop();
        curr_time = 0;
        events_ind = 0;
        ui->l_status->setText("Played through all events");
        /*QString last = "last: ";
        last += QString::number(g1s);
        last += ", ";
        last += QString::number(g2s);
        last += ", ";
        last += QString::number(g3s);
        last += ", ";
        last += QString::number(g4s);
        last += ", ";
        last += QString::number(g5s);
        last += ", ";
        last += QString::number(g6s);
        last += ", ";
        last += QString::number(g7s);
        last += ", ";
        last += QString::number(g8s);
        ui->l_status->setText(last);*/
    }
}

void BeeChimes::play_gates(int g1_a, int g2_a, int g3_a, int g4_a, int g5_a, int g6_a, int g7_a, int g8_a)
{
    play_g1(g1_a);
    play_g2(g2_a);
    play_g3(g3_a);
    play_g4(g4_a);
    play_g5(g5_a);
    play_g6(g6_a);
    play_g7(g7_a);
    play_g8(g8_a);
}

void BeeChimes::play_g1(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g1_qmps[g1_plays % num_players]->setVolume(vol);
    g1_qmps[g1_plays % num_players]->play();
}

void BeeChimes::play_g2(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g2_qmps[g2_plays % num_players]->setVolume(vol);
    g2_qmps[g2_plays % num_players]->play();
}

void BeeChimes::play_g3(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g3_qmps[g3_plays % num_players]->setVolume(vol);
    g3_qmps[g3_plays % num_players]->play();
}

void BeeChimes::play_g4(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g4_qmps[g4_plays % num_players]->setVolume(vol);
    g4_qmps[g4_plays % num_players]->play();
}

void BeeChimes::play_g5(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g5_qmps[g5_plays % num_players]->setVolume(vol);
    g5_qmps[g5_plays % num_players]->play();
}

void BeeChimes::play_g6(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g6_qmps[g6_plays % num_players]->setVolume(vol);
    g6_qmps[g6_plays % num_players]->play();
}

void BeeChimes::play_g7(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g7_qmps[g7_plays % num_players]->setVolume(vol);
    g7_qmps[g7_plays % num_players]->play();
}

void BeeChimes::play_g8(int active)
{
    if(active == 0)
        return;
    int vol = (100 - (100 * pow(vol_adjust, active))) / 100 * max_vol;
    g8_qmps[g8_plays % num_players]->setVolume(vol);
    g8_qmps[g8_plays % num_players]->play();
}


void BeeChimes::on_vs_volume_sliderMoved(int position)
{
    max_vol = position;
    //QString stat = "silent mode lads: ";
    //stat += QString::number(position);
    //ui->l_status->setText(stat);
}

void BeeChimes::on_pb_pause_clicked()
{
    timer->stop();
}

void BeeChimes::on_pb_stop_clicked()
{
    timer->stop();
    curr_time = 0;
    events_ind = 0;
}

void BeeChimes::on_pb_back_clicked()
{
    // need to figure out how to do this :)
}
