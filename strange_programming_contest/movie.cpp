#include <bits/stdc++.h>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


class drawable{
    public:
        drawable(vector<string> object){
            figure = object;
        }
        vector<string> getFigure(){
            return figure;
        }
    
    private:
        vector<string> figure{
            R"(        _____      )",
            R"(    .-,;='';_),-.  )",
            R"(     \_\(),()/_/   )",
            R"(       (,___,)     )",
            R"(      ,-/`~`\-,___ )",
            R"(     / /).:.('--._))",
            R"(    {_[ (_,_)      )",
            R"(        | Y |      )",
            R"(       /  |  \     )",
            R"(       """ """     )",

        };
};
class Canvas{
    public:
        void clear(){
            mCurrentCanvas = mCleanCanvas;
            system("clear");
        }
        void addFigure(drawable t, int x, int y){
            vector<string> tt = t.getFigure();
            for(int i = 0; i < tt.size(); ++i){
                for(int j = 0; j < tt[i].length(); ++j){
                    mCurrentCanvas[y+i][x+j] = tt[i][j];
                }
            }
        }
        void draw(){
            for(auto str: mCurrentCanvas)
                cout << str << endl;
        }
    private:
        vector<string> mCleanCanvas{
R"(                            .                                            .)",
R"(     *   .                  .              .        .   *               .)",
R"(  .         .                     .       .           .      .          .)",
R"(        o                             .                                .)",
R"(         .              .                  .                          .)",
R"(          0     .                                                      )",
R"(                 .          .                 ,                ,    , )",
R"( .          \          .                                            .  )",
R"(      .      \   ,                                                     )",
R"(   .          o     .                 .                   .            .)",
R"(     .         \                 ,             .                .        )",
R"(               #\##\#      .                              .        .      )",
R"(             #  #O##\###                .                        .        )",
R"(   .        #*#  #\##\###                       .                     ,    )",
R"(        .   ##*#  #\##\##               .                     .            )",
R"(      .      ##*#  #o##\#         .                             ,       .  )",
R"(          .     *#  #\#     .                    .             .          ,)",
R"(                      \          .                         .               )",
R"(____^/\___^--____/\____O______________/\/\---/\___________---______________)",
R"(   /\^   ^  ^    ^                  ^^ ^  '\ ^          ^       ---          )",
R"(         --           -            --  -      -         ---  __       ^      )",
R"(   --  __                      ___--  ^  ^                         --  __   )"
        };
        vector<string> mCurrentCanvas;

};



int main(){
    int cycle = 10, step = 1;
    int direction = 1;

    Canvas* myCanvas = new Canvas();

    vector<string> figure1{
            R"(        _____      )",
            R"(    .-,;='';_),-.  )",
            R"(     \_\(),()/_/   )",
            R"(       (,___,)     )",
            R"(      ,-/`~`\-,___ )",
            R"(     / /).:.('--._))",
            R"(    {_[ (_,_)      )",
            R"(        | Y |      )",
            R"(       /  |  \     )",
            R"(       """ """     )",

    };
    vector<string> figure2{
            R"(        _____      )",
            R"(    .-,;='';_),-.  )",
            R"(     \_\(),()/_/   )",
            R"(       (,___,)     )",
            R"(      ,-/`~`\-,___ )",
            R"(     / /).:.('--._))",
            R"(    {_[ (_,_)      )",
            R"(        | Y |      )",
            R"(       /  |  \     )",
            R"(       """ """     )",

    };
    drawable actor1(figure1), actor2(figure2);

    int curY1 = 5, curY2 = 10;
    int curX1 = 0, curX2 = 20;
    int cnt = 0;
    int direction1 = 1, direction2 = -1;
    for(int i = 0; i < 103; ++i){
        myCanvas->clear();
        myCanvas->addFigure(actor1, curX1, curY1);
        myCanvas->addFigure(actor2, curX2, curY2);
        curY1+= direction1*step;
        curY2+= direction2*step;
        ++cnt;
        myCanvas->draw();
        sleep_for(0.005s);
        if(cnt == 5){
            direction1 *= -1;
            direction2 *= -1;
            cnt = 0;
        }
    }

    delete myCanvas;

}