## **Уравнения продольного канала движения БПЛА:**
$$m\cdot\frac{dV}{dt} = P-G\cdot\sin(\theta)-X$$
$$m\cdot V\cdot\frac{d\theta}{dt} = P\cdot\alpha-G\cdot\cos(\theta)+Y$$
$$J_z\cdot\frac{d\omega_z}{dt} = M_{R_z} +M_{A_z}$$
$$\frac{d\vartheta}{dt}=\omega_z$$
$$\frac{dx}{dt}=V\cdot\cos(\theta)$$
$$\frac{dy}{dt}=V\cdot\sin(\theta)$$
$$\theta=\vartheta-\alpha$$
Где:
$$X=\frac{1}{2}\cdot C_x\cdot\rho\cdot S\cdot V^2,\qquad Y=\frac{1}{2}\cdot C_y\cdot\rho\cdot S\cdot V^2$$
$$G=m\cdot g$$

## **Уравнения бокового канала движения БПЛА:**
$$m\cdot V\cdot\cos(\theta)\cdot\frac{d\Psi}{dt}=P\cdot\beta+Z$$
$$J_x\cdot\frac{d\omega_x}{dt}=M_{R_x}+M_{A_x}$$
$$J_y\cdot\frac{d\omega_y}{dt}=M_{R_y}+M_{A_y}$$
$$\frac{d\psi}{dt}=\frac{1}{cos(\vartheta)}\cdot\omega_y$$
$$\frac{d\gamma}{dt}=\omega_x-\omega_y\cdot\tan(\vartheta)$$
$$\frac{dz}{dt}=-V\cdot\cos(\theta\cdot\sin(\Psi))$$
$$\beta=\Psi-\psi$$
Где:
$$Z=\frac{1}{2}\cdot C_z\cdot\rho\cdot S\cdot V^2$$