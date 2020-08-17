#include <windows.h>
#include <conio.h>

int main() {
	int W = 20, S = W * W, *map, z[3] = { 0 }, len = 3, i, c = 'D', C, *p, a;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) { 25, 0 });
	for (srand(map = calloc(S, 4)), C = map[1] = -1; C - 27; _sleep(100)) {
		if (_kbhit())C = _getch() & 95, C - 65 && C - 68 &&
			C - 83 && C - 87 || ((C ^ c) & 20) - 4 && (c = C);
		p = z + !!(c & 16), *p += c / 6 & 1 ? 1 : -1, *p = (*p + W) % W;
		if (a = 1, map[z[2] = *z + z[1] * W] > 0 )break;
		for (; map[z[2]] && (map[i = rand() % S] || (--map[i], ++len, --a)););
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { 0, 0 });
		for (map[z[2]] = len, i = 0; i < S; ++i % W || _cputs("|\n"))
			_cputs(map[i] > 0  ? ((map[i] -= a), "()") : map[i] ? "00" : "  ");
        // while(1);
	}
}