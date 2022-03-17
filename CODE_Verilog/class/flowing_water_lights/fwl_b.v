module flowing_water_lights (
    input  wire       clk   ,
	input  wire       rst   ,
	input  wire       button,
	output reg  [7:0] led
);
reg [27:0] cnt;
reg flag;
wire rst_n=~rst;

always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n)    
            flag <= 0;
        else if(button)       
            flag <= 1;
    end

always@(posedge clk or negedge rst_n) 
    begin
        if(~rst_n || flag == 0)                    
            cnt <= 0;
        else if (cnt == 100000000-1)   
            cnt <= 0;
        //else if(cnt == 3)               cnt <= 0;
        else                           
            cnt <= cnt + 1;
    end

always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n || flag == 0)            
            led <= 8'b00000000;
        else if(cnt == 100000000-1) 
        //else if(cnt == 3)               
            led <= { led[6:0],led[7] };
    end
endmodule