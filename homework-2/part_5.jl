include("part_1.jl")
include("part_2.jl")
include("part_3.jl")

num_particles = 100
u0 = 0.1 .+ .4 * rand(2, num_particles) # initial positions of the particles
tspan = [0, 1]
dt = 1/1024
partdata = solve(ForwardEuler(),u0,rhs!,tspan,dt,5;num_saved_steps=1)[1] # generate the positions of the particles

scatter(partdata[1,:,1],partdata[2,:,1],label = "initial", xlim = [-1,1], ylim = [-1,1]) # initial pos of the particles
scatter!(partdata[1,:,2],partdata[2,:,2],label="final") # final pos of the particles
xlabel!("x axis")
ylabel!("y axis")
title!("Initial positions and final positions of the particles")
savefig("C:\\Users\\admin\\Desktop\\Rice\\2022 fall\\caam419\\initialandfinal.png")

tspan = [0, 5]
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
    posmat2 = solve(ExplicitMidpoint(u0),u0,rhs!,tspan,dt[m], 5;num_saved_steps=1)[1]# try different dt for the problem
    errormid[m] = norm(posmat2[:,:,2]-posmat2[:,:,1]) # calculate the error for explictmidpoint method
    num_rhs2[m] = solve(ExplicitMidpoint(u0),u0,rhs!,tspan,dt[m], 5;num_saved_steps=1)[2] # store the number of evaluation of rhs!
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
