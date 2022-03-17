module flowing_water_lights (
    input  wire       clk   ,
	input  wire       rst   ,
	input  wire       button,
	output reg  [7:0] led
);

reg [3:0] cnt;//c4=b0001:1s
reg [7:0] state;
wire rst_n=~rst;
reg flag;

assign cnt_end=(cnt==4'b1000);//8s一个周期
assign cnt_inc=(flag==1);


always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n)
            flag<=0;
        else if(button)
            flag<=1;
    end
    
always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n||flag==0) 
            cnt<=4'b0;
        else if(cnt_end)
            cnt<=4'b0;
        else if(cnt_inc)
            cnt<=cnt+4'b1;
    end
    
always @(posedge clk or negedge rst_n)
    begin
        if(~rst_n||flag==0) 
            state <= 8'd0;
        else if( cnt < 4'b0001 )
            state <= 8'd0;
        else if( cnt >= 4'b0001 && cnt < 4'b0010 )
            state <= 8'd1;
        else if( cnt >= 4'b0010 && cnt < 4'b0011 )
            state <= 8'd2;
        else if( cnt >= 4'b0011 && cnt < 4'b0100 )
            state <= 8'd3;
        else if( cnt >= 4'b0100 && cnt < 4'b0101 )
            state <= 8'd4;
        else if( cnt >= 4'b0101 && cnt < 4'b0110 )
            state <= 8'd5;
        else if( cnt >= 4'b0110 && cnt < 4'b0111 )
            state <= 8'd6;
        else if( cnt >= 4'b0111 && cnt < 4'b1000 )
            state <= 8'd7;
    end

always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n||flag==0)
            led<=8'b00000000;
        else
            begin
                case(state)
                    8'd0:led<=8'b00000001;
                    8'd1:led<=8'b00000010;
                    8'd2:led<=8'b00000100;
                    8'd3:led<=8'b00001000;
                    8'd4:led<=8'b00010000;
                    8'd5:led<=8'b00100000;
                    8'd6:led<=8'b01000000;
                    8'd7:led<=8'b10000000;
                    default:led<=8'b00000000;
                endcase
            end
    end
endmodule