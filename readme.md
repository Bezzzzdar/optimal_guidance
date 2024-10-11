## Модель пространственного движения БПЛА
$$\frac{dV}{dt} = g(n_{ax}-\sin\theta)$$
$$\frac{d\theta}{dt} = \frac{g}{V}(n_{ay}\cos\gamma_{a}-n_{az}\sin\gamma_{a}-\cos\theta )$$
$$\frac{d\Psi}{dt}=-\frac{g}{V\cos\theta}(n_{ay}\sin\gamma_{a}+n_{az}\cos\gamma_{a})$$
$$\frac{dx}{dt}=V\cos\theta\cos\Psi$$
$$\frac{dy}{dt}=V\sin\theta$$
$$\frac{dz}{dt}=-V\cos\theta\sin\Psi$$
$$\frac{d\vartheta}{dt}=\omega_{y}\sin\gamma+\omega_{z}\cos\gamma$$
$$\frac{d\gamma}{dt}=\omega_{x}-\tan\vartheta(\omega_{y}\cos\gamma+\omega_{z}\sin\gamma)$$
$$\frac{d\psi}{dt}=\frac{1}{cos\vartheta}(\omega_{y}\cos\gamma+\omega_{z}\sin\gamma)$$
$$\frac{d\omega_{x}}{dt}=\frac{1}{J_{x}}[(J_{y}-J_{z})\omega_{y}\omega_{z}+qSlm_{x}]$$
$$\frac{d\omega_{y}}{dt}=\frac{1}{J_{y}}[(J_{z}-J_{x})\omega_{x}\omega_{z}-K\omega_{z}+qSlm_{y}]$$
$$\frac{d\omega_{z}}{dt}=\frac{1}{J_{z}}[(J_{x}-J_{y})\omega_{x}\omega_{y}+K\omega_{y}+qSb_{a}m_{z}]$$
$$\sin\vartheta_{a}=-\cos\beta\cos\gamma\cos\vartheta\sin\alpha-\cos\vartheta\sin\beta\sin\gamma+\cos\alpha\cos\beta\sin\vartheta$$
$$\cos\vartheta_{a}\sin\psi_{a}=\cos\alpha\cos\beta\cos\vartheta\sin\psi+\cos\beta\sin\alpha(\cos\psi\sin\gamma+\cos\gamma\sin\vartheta\sin\psi)+\sin\beta(\sin\gamma\sin\vartheta\sin\psi-\cos\gamma\cos\psi)$$
$$\cos\vartheta_{a}\sin\gamma_{a}=\cos\alpha\sin\beta\sin\vartheta+\cos\beta\cos\vartheta\sin\gamma-\sin\alpha\sin\beta\cos\beta\cos\gamma\cos\vartheta$$

Где:
$$n_{ax}=\frac{P\cos\alpha\cos\beta-X_{a}}{mg}$$
$$n_{ay}=\frac{P\sin\alpha+Y_{a}}{mg}$$
$$n_{az}=\frac{-P\cos\alpha\sin\beta+Z_{a}}{mg}$$
$$X_{a}=\frac{1}{2}\cdot C_x\cdot\rho\cdot S\cdot V^2$$
$$Y_{a}=\frac{1}{2}\cdot C_y\cdot\rho\cdot S\cdot V^2$$
$$Z_{a}=\frac{1}{2}\cdot C_z\cdot\rho\cdot S\cdot V^2$$
$$\alpha=\vartheta-\theta$$
$$\beta=\Psi-\psi$$