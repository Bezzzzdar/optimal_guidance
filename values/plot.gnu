# ��������� ����������� ��� CSV
set datafile separator ","

# --- ������ ����������� ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10" 
set output "./plots/Trajectory.png"
set title "�����������"
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set grid

# ���������� � ��������� ������
splot "./values/target_values.csv" using 1:2:3 with linespoints title "����������"

# ��������� ���� � ������������
set output

# --- ������ ����������� �������� �� ������� ---
set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output "./plots/Speed.png"
set title "����������� �������� �� �������"
set xlabel "�����"
set ylabel "��������"
set grid

# ���������� � ��������� ������
plot "./values/target_values.csv" using 5:4 with linespoints title "��������"

# ��������� ���� � ������������
set output