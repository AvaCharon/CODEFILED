module holiday_lights (
    input  wire        clk   ,
	input  wire        rst   ,
	input  wire        button,
    input  wire [ 2:0] switch,
	output reg  [15:0] led
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
            begin
                case(switch)
                    3'b0:led<=16'b1;
                    3'b1:led<=16'b11;
                    3'b10:led<=16'b111;
                    3'b11:led<=16'b1111;
                    3'b100:led<=16'b11111;
                    3'b101:led<=16'b111111;
                    3'b110:led<=16'b1111111;
                    3'b111:led<=16'b11111111;
                    default:led<=16'b0;                          
                endcase
            end
        else if(cnt == 100000000-1) 
        //else if(cnt == 3)               
            led <= { led[14:0],led[15] };
    end
endmodule