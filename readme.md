## Модель динамики БПЛА
### Модель пространственного движения БПЛА, рассматриваемого как материальная точка
$$\frac{dv}{dt}=g(n_{x}-\sin(\theta))$$
$$\frac{d\theta}{dt}=\frac{g}{v}(n_{y}-\cos(\theta))$$
$$\frac{d\varphi}{dt}=-\frac{g}{v}\frac{n_{z}}{\cos(\theta)}$$
$$\frac{dx}{dt}=v\cos(\theta)\cos(\varphi)$$
$$\frac{dy}{dt}=v\sin(\theta)$$
$$\frac{dz}{dt}=-v\cos(\theta)\sin(\varphi)$$

### Вектор состояния
$$X=(v,\theta,\varphi,x,y,z)^T$$

### Вектор управления
$$u=n=(n_{x},n_{y},n_{z})^T$$

## Оптимизация динамики системы с коррекцией параметров структуры управления
### Основная задача оптимального управления
$$\dot{x}=f(x,u,t)$$
Требуется минимизировать терминальный функционал:
$$I=V_f(x, t_f)$$
при:
$$x(t_0)=x_0$$, $$x_i(t_f)=x_{fi}$$, $$i=\overline{1,k}$$, $$k \le n$$, $$|u|\le u_m$$,
$$f(x,u,t) = f_1(x,t)+f_2(x,t)u$$
Гамильтониан системы:
$$H = p^Tf=p^T[f_1(x,t)+f_2(x,t)u]=H_1+H_2u$$
Из принципа максимума следует:
$$\dot{x}^T=\frac{\partial H}{\partial p}$$, $$\dot{p}^T=-\frac{\partial H}{\partial p}$$
Уравнение для выбора управления:
$$H(x,u_0,p,t)=\inf_{u\in U} H(x,u,p,t)$$
откуда:
$$u = 
\begin{cases} 
-u_m \, \text{sign}(H_2), & H_2 \ne 0, \\
u_s, & H_2 = 0.
\end{cases}$$, где $$u_s$$ - особое управление
Условие трансверсальности:
$$\bigg[\bigg(\frac{\partial V_f}{\partial x}-p^T\bigg)\delta x+\bigg(H+\frac{\partial V_f}{\partial t}\bigg)\delta t\bigg]\bigg|_0^f=0$$
Отсюда определяем граничные условия для вектора состояния, сопряженных переменных:
$$p^T(t_f)=\frac{\partial V_f}{\partial x}$$, $$\bigg(H+\frac{\partial V_f}{\partial t}\bigg)_f=0$$