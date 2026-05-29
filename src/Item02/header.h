#pragma once

class GamePlayer {
 public:
  GamePlayer();
  ~GamePlayer();
  int* get_score() { return scores; }
  void update_score(int a[], int n);

  int* b;

 protected:
 private:
  // enum { NumTurns = 5 };
  static const int NumTurns = 5;  // declaration
  int scores[NumTurns];
};