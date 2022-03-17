module flowing_water_lights (
    input  wire       clk   ,
	input  wire       rst   ,
	input  wire       button,
	output reg  [7:0] led
);

reg [31:0] cnt;//cnt==100_000_000:1s
reg [7:0] state;
wire rst_n=~rst;

assign cnt_end=(cnt==32'd800_000_000);//8s一个周期
assign cnt_inc=(button==1);

always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n) 
            cnt<=32'b0;
        else if(cnt_end)
            cnt<=32'b0;
        else if(cnt_inc)
            cnt<=cnt+32'b1;
    end
    
always @(posedge clk or negedge rst_n)
    begin
        if(~rst_n) 
            state <= 8'd0;
        else if( cnt < 32'd100_000_000 )
            state <= 8'd0;
        else if( cnt >= 32'd100_000_000 && cnt < 32'd200_000_000 )
            state <= 8'd1;
        else if( cnt >= 32'd200_000_000 && cnt < 32'd300_000_000 )
            state <= 8'd2;
        else if( cnt >= 32'd300_000_000 && cnt < 32'd400_000_000 )
            state <= 8'd3;
        else if( cnt >= 32'd400_000_000 && cnt < 32'd500_000_000 )
            state <= 8'd4;
        else if( cnt >= 32'd500_000_000 && cnt < 32'd600_000_000 )
            state <= 8'd5;
        else if( cnt >= 32'd600_000_000 && cnt < 32'd700_000_000 )
            state <= 8'd6;
        else if( cnt >= 32'd700_000_000 && cnt < 32'd800_000_000 )
            state <= 8'd7;
    end

always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n)
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