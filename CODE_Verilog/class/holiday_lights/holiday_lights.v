module holiday_lights (
    input  wire        clk   ,
	input  wire        rst   ,
	input  wire        button,
    input  wire [ 2:0] switch,
	output reg  [15:0] led
);

reg [31:0] cnt;//cnt==100_000_000:1s
reg [2:0] state;
wire rst_n=~rst;

assign cnt_end=(cnt==32'd1600_000_000);//16s一个周期
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
            state <= 2'd0;
        else if( cnt < 32'd100_000_000 )
            state <= 2'd0;
        else if( cnt >= 32'd100_000_000 && cnt < 32'd1600_000_000 )
            state <= 2'd1;
    end

always@(posedge clk or negedge rst_n)
    begin
        if(~rst_n)
            led<=16'b0000000000000000;
        else
            begin
                case(state)
                    2'd0:
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
                        default:led<=16'b1;                          
                        endcase
                    end
                    2'd1:led<={led[14:0],led[15]};
                    default:led<=16'b0000000000000000;
                endcase
            end
    end

endmodule