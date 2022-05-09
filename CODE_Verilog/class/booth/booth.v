module booth (
    input  wire        clk  ,
	input  wire        rst_n,
	input  wire [15:0] x    ,
	input  wire [15:0] y    ,
	input  wire        start,
	output reg  [31:0] z    ,
	output wire        busy 
);

reg[33:0]   x_reg;
reg[33:0]   nx_reg;
reg[33:0]   res_reg;
reg[1:0]    curr_state;
reg[1:0]    next_state;
reg[7:0]    cnt;
reg         busy_reg;

parameter   IDLE  = 2'b00, 
            ADD   = 2'b01,
            SHIFT = 2'b10,
            OUTPUT= 2'b11;

assign busy = busy_reg;

always @(posedge clk or negedge rst_n)begin
    if(~rst_n)begin
        curr_state = IDLE;
    end
    else begin
        curr_state <= next_state;
    end
end

always @(*)begin
    case(curr_state)
        IDLE:begin
            if(start)begin
                busy_reg <= 1;
                next_state = ADD;
            end
            else begin
                next_state = IDLE;
            end
        end
        ADD :next_state = SHIFT;
        SHIFT:begin
            if(cnt==16)begin
                next_state = OUTPUT;
            end
            else begin
                next_state = ADD;
            end
        end
        OUTPUT:next_state = IDLE;
    endcase
end

always @(posedge clk or negedge rst_n)begin
    if(~rst_n)begin
        z<=0;
        cnt<=0;
        x_reg<=0;
        nx_reg<=0;
        res_reg<=0;
    end
    else begin
        case(curr_state)
            IDLE:begin
                x_reg <= {x[15],x,{(17){1'b0}}};
                nx_reg<= {~{x[15],x}+1,{(17){1'b0}}};
                res_reg<={{(17){1'b0}},y,1'b0};
                cnt<=0;
            end
            ADD :begin
                case(res_reg[1:0])
                    2'b01       : res_reg <= res_reg + x_reg;
                    2'b10       : res_reg <= res_reg +nx_reg;
                    2'b00,2'b11 : res_reg <= res_reg;
                endcase
                cnt<=cnt+1;
            end
            SHIFT :begin
                res_reg <= {res_reg[33],res_reg[33:1]};
            end
            OUTPUT:begin
                busy_reg <= 0;
                z <= res_reg[32:1];
            end
        endcase
    end
end

endmodule