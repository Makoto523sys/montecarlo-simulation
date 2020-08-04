# montecarlo-simulation

これは$\int_{-\infty}^\infty \mathrm{exp}(-x^2)$をモンテカルロ法によって計算するプログラムです.

ただ,これはこのまま計算するのは結構無理ゲーなので次のような変形を行います.
$$
\begin{align}
	y	&= \frac{1}{x+1}\\
	とおくと\\
	dy	&= -\frac{1}{(x+1)^2}dx\\
	また積分&区間は次のように変化する.\\
	-\infty	<	&x	<	\infty	\leftrightarrow 0	\le		y	\le		1\\
	従って積&分は次のように置き換えられる.\\
	\int_0^1\mathrm{exp}&(-(\frac{1}{y}-1)^2) \frac{1}{y^2}dy
\end{align}
$$
以上のことを頭に入れれば,ソースコードを追っていて分けわからんくなることはないはずです.