#ifndef IMPTIMER__H_
#define IMPTIMER__H_
using namespace std ;
class ImpTimer{
public:
    ImpTimer();
    ~ImpTimer();
    int start_tick_;
    int paused_tick_;
    bool is_paused_;
    bool is_started_;
    void start();
    void stop();
    void paused();
    void unpaused();
    int get_ticks();
    bool is_paused();
    bool is_started();
};

#endif // IMPTIMER__H_
