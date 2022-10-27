function rhs!(du,u,t,parameters)
    v_x(y, t) = -sin(pi*y)*cos(pi*t/parameters) # velocity functions
    v_y(x, t) = sin(pi*x)*cos(pi*t/parameters)
    for i = 1:size(u,2)
        du[1,i] = v_x(u[2,i], t)
        du[2,i] = v_y(u[1,i], t)
    end
end
#u = rand(2,100)
#du = zeros(2,100)
#t = 1
#C = 5
#@code_warntype rhs!(du, u, t, C)
#@time rhs!(du,u,t,C)