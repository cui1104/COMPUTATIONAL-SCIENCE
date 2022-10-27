include("part_1.jl")
include("part_2.jl")
using Plots
#u0 = randn(2,100)
#tspan = [0,5]
#dt = 1/16
#parameters = 5
#@code_warntype solve(ForwardEuler(),u0,rhs!, tspan, dt, parameters;num_saved_steps=1)
#@code_warntype solve(ExplicitMidpoint(u0),u0,rhs!, tspan, dt, parameters;num_saved_steps=1)

num_particles = 100
u0 = 0.1 .+ .4 * rand(2, num_particles)
tspan = [0.0, 5.0]
dt = [1/16, 1/32, 1/64, 1/128, 1/256, 1/512, 1/1024]

erroreuler= zeros(1,7)
num_rhs = zeros(1,7)

for m=1:7
    posmat = solve(ForwardEuler(),u0,rhs!,tspan,dt[m], 5;num_saved_steps=1)[1] # try different dt for the problem
    erroreuler[m] = norm(posmat[:,:,2]-posmat[:,:,1]) # calculate the errordt
    num_rhs[m] = solve(ForwardEuler(),u0,rhs!,tspan,dt[m], 5;num_saved_steps=1)[2] # store the number of evaluation of rhs!
end

errormid = zeros(1,7)
num_rhs2 = zeros(1,7) 

for m=1:7
    posmat2 = solve(ExplicitMidpoint(u0),u0,rhs!,tspan,dt[m], 5;num_saved_steps=1)[1]
    errormid[m] = norm(posmat2[:,:,2]-posmat2[:,:,1])
    num_rhs2[m] = solve(ExplicitMidpoint(u0),u0,rhs!,tspan,dt[m], 5;num_saved_steps=1)[2]
end

errordt = zeros(2,7)
errordt[1,:]= erroreuler # store errors by two methods in one matrix for plotting
errordt[2,:]=errormid

plot(dt, transpose(errordt),marker=(:circle,5), xaxis=:log, yaxis=:log,label = ["ForwardEuler" "ExplicitMidPoint"],legend=:bottomright)
xlabel!("Timestep size")
ylabel!("Error")
title!("Error vs. timestep")
savefig("C:\\Users\\admin\\Desktop\\Rice\\2022 fall\\caam419\\errorvsdt.png")

plot([transpose(num_rhs),transpose(num_rhs2)], [transpose(erroreuler),transpose(errormid) ],marker=(:circle,5),xaxis=:log, yaxis=:log,label = ["ForwardEuler" "ExplicitMidPoint"])
xlabel!("Number of rhs! ")
ylabel!("Error")
title!("Error vs. Number of rhs!")
savefig("C:\\Users\\admin\\Desktop\\Rice\\2022 fall\\caam419\\errorvsrhs.png")

tspan2 = [0.0,10.0]
gifdt = solve(ForwardEuler(),u0,rhs!,tspan2, 1/1024 , 5 ;num_saved_steps= 160)[1] # gif for forwardeuler method

anime = @animate for l = 1:161
    p1 = plot()
    scatter!(gifdt[1,:,l], gifdt[2,:,l], xlim = [-1,1], ylim = [-1,1],label="particle") # store the scatter plot as frame every iteration
end
gif(anime)

# gifdt_mid = solve(ExplicitMidpoint(u0),u0,rhs!,tspan2, 1/1024 , 5 ;num_saved_steps= 160)[1] # gif for ExplicitMidPoint method
# anime2 = @animate for l = 1:161
#     p2 = plot()
#     scatter!(gifdt_mid[1,:,l], gifdt_mid[2,:,l], xlim = [-1,2], ylim = [-1,2],label="particle") # store the scatter plot as frame every iteration
# end
# gif(anime2)
