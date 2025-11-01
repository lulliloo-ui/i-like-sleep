#include <iostream>

 int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{
  int ** mtx = nullptr;
  mtx = new * [rows];
  for (int i = 0; i < rows; i ++)
  {
    int a = lns[i];
    mtx[i] = new [a];
  }
  int b = 0;
  for (int j = 0; j < rows; ++j)
  {
    int k = 0;
    while (k < lns[j])
    {
      mtx[j][k] = t[b];
      k++;
      b++;
    }
  }
}
void destroy(int ** mtx, size_t created)
{
  for (size_t i = 0; i < created; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** create(size_t rows, size_t cols)
{
  int ** mtx = new int * [rows];
  size_t created = 0;
  try
  {
    for (; created < rows; ++created) //size_t i = 0; i < rows; ++i
    {
      mtx[created] = new int[cols];
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}

int ** construct(int ** mtx, int init, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
}

void input(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}
void output(int ** mtx, size_t rows , size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < cols; ++j)
    {
      std::cout << " " << mtx[i][j];
    }
    std::cout << "\n";
  }
}
int main() {
  size_t r = 0, c = 0;
  std::cin >> r >> c;
  if (!std::cin)
  {
    std::cerr << "plohoy input\n";

    return 1;
  }
  int ** matrix = nullptr;
  try
  {
    matrix = create(r, c);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';

    return 1;
  }
  std::cout << "created\n";
  construct(matrix, 0, r, c);
  input(matrix, r, c);
  if (!std::cin)
  {
    destroy(matrix, r);
    std::cerr << "input error\n";
    return 1;
  }
  output(matrix, r, c);
  destroy(matrix, r);
}
