## Модель пространственного движения БПЛА, рассматриваемого как материальная точка
$$\frac{dv}{dt}=g(n_{x}-\sin(\theta))$$
$$\frac{d\theta}{dt}=\frac{g}{v}(n_{y}-\cos(\theta))$$
$$\frac{d\varphi}{dt}=-\frac{g}{v}\frac{n_{z}}{\cos(\theta)}$$
$$\frac{dx}{dt}=v\cos(\theta)\cos(\varphi)$$
$$\frac{dy}{dt}=v\sin(\theta)$$
$$\frac{dz}{dt}=-v\cos(\theta)\sin(\varphi)$$

## Вектор состояния
$$X=(v,\theta,\varphi,x,y,z)^T$$

## Вектор управления
$$u=n=(n_{x},n_{y},n_{z})^T$$