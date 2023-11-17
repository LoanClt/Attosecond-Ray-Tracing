nombre_de_rayons = 10;
nombre_de_points_du_dioptre = 1000;
diopte_y_min = -1;
dioptre_y_max = 1;
dioptre_y = linspace(-1,1,nombre_de_points_du_dioptre);
source_x = ones(nombre_de_rayons)*(-10);
source_y = zeros(nombre_de_rayons);

%Equation du dioptre
a = -0.1;
b = 0;
c = 0;
dioptre_x = a*dioptre_y.^2 + b*dioptre_y + c;

%Détermination des points d'impacts
impact_y = zeros(nombre_de_rayons);
impact_tangente_y = [[]];
for k=1:nombre_de_rayons
    k_prime = nombre_de_points_du_dioptre/nombre_de_rayons*k;
    impact_y(k) = dioptre_y(k_prime);
   
end

impact_x = a*impact_y.^2 + b*impact_y + c;

%Equation des droites


y_test = linspace(-0.5,0.5, 100);

x_test = -1/(2*impact_y(k))*(y_test-impact_y(k)) + impact_x(k);


% kk = 3;
% m = (impact_y(kk)-source_y(kk))/(impact_x(kk) - source_x(kk));
% b = source_y(kk)-m*source_x(kk);
% xc = linspace(-10, 0)
% yc = m*xc+b


k=5
% coeffdirecteur_rayon-k
m1=(impact_y(k)-source_y(k))/(impact_x(k)-source_x(k)) 
% coeffdirecteur_normal
impact_y(k)
m2=(-2*impact_y(k))
% angle_entre_deux_droite
alpha=atan(abs((m1-m2)./(1+(m1*m2))))
hold on
scatter(source_x, source_y)
scatter(impact_x, impact_y)
for k=1:nombre_de_rayons
    k_prime = nombre_de_points_du_dioptre/nombre_de_rayons*k
    plot([source_x(k) impact_x(k)], [source_y(k) impact_y(k)], "r")
    if k_prime ~= nombre_de_points_du_dioptre
        plot([dioptre_x(k_prime-1) dioptre_x(k_prime+1)], [dioptre_y(k_prime-1) dioptre_y(k_prime+1)], 'c', 'LineWidth',8)
    else
        plot([dioptre_x(k_prime-1) dioptre_x(k_prime)], [dioptre_y(k_prime-1) dioptre_y(k_prime)], 'c', 'LineWidth',8)
    end

end
plot(dioptre_x, dioptre_y, 'black')
plot(xc,yc, "black")
