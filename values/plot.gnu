# ��������� ����������� ��� CSV
set datafile separator ","

# --- ������ ����������� ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "Trajectory.png"
set title "�����������"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set grid

# ���������� � ��������� ������
splot "target_values.csv" using 1:2:3 with linespoints title "����������"

# ��������� ���� � ������������
set output

# --- ������ ����������� �������� �� ������� ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "Speed.png"
set title "����������� �������� �� �������"
set xlabel "�����"
set ylabel "��������"
set grid

# ���������� � ��������� ������
plot "target_values.csv" using 5:4 with linespoints title "��������"

# ��������� ���� � ������������
set output