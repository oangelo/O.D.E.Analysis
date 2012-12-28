#ifndef LORENZ_H
#define LORENZ_H 

TEST(Lorenz, Lyapunov) {
       
       type_container variable(3), parameter(3);
       variable[0] = -3.16;
       variable[1] = -5.31;
       variable[2] = 13.31;
       //Parameters from wikipedia
       parameter[P_SIGMA_LORENZ] = 10;
       parameter[P_GAMMA_LORENZ] = 28;
       parameter[P_BETA_LORENZ] = 8.0 / 3.0;
       
       AdamsMoulton<LorenzFunction> attractor(variable, parameter, 0.001);
       type_container lambda = lyapunov<Jacobian_LorenzFunction> (attractor, pow(10, 6), pow(10, 7), 1, "teste");
       
       for(auto iten: lambda)
           std::cout << iten << std::endl;

       EXPECT_NEAR(lambda[0], 0.907, 0.01);
       EXPECT_NEAR(lambda[1], 0.0000, 0.001);
       EXPECT_NEAR(lambda[2], -14.574, 0.01);
         
}

#endif /* LORENZ_H */
