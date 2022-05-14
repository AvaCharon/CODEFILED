module booth(
    input wire clk,
    input wire rst_n,
    input wire start,
    input wire [15:0] x,
    input wire [15:0] y,
    output reg busy,
    output reg [31:0] z 
    );
reg [16:0] tmp;
reg [16:0] x_reg;
reg [16:0] nx_reg;
reg [16:0] y_reg;
reg [5:0] cnt;

always @(posedge start) begin
    if(start) begin
        tmp=17'h00000;
        busy<=0;
        x_reg<={x[15],x[15:0]};
        nx_reg<={~x[15],~x[15:0]+1};
        y_reg<={y[15:0],1'b0};
        cnt<=0;
    end 
end   
always @(negedge start) begin
    if(!start) busy<=1;
end
always @(posedge clk or negedge rst_n) begin
    if(!rst_n) begin
        busy<=0;
        z<=0;
    end
    if(busy&&cnt<15) begin
        cnt=cnt+1;
        case(y_reg[1:0])
            2'b00: begin
                y_reg={tmp[0],y_reg[16:1]};
                tmp={tmp[16:15],tmp[15:1]};
            end
            2'b01: begin
                tmp=tmp+x_reg;
                y_reg={tmp[0],y_reg[16:1]};
                tmp={tmp[16:15],tmp[15:1]};
            end    
            2'b10: begin
                tmp=tmp+nx_reg;
                y_reg={tmp[0],y_reg[16:1]};
                tmp={tmp[16:15],tmp[15:1]};
            end    
            2'b11: begin
                y_reg={tmp[0],y_reg[16:1]};
                tmp={tmp[16:15],tmp[15:1]};
            end    
            default:;
        endcase
    end
    else if(busy&&cnt==15) begin
        case(y_reg[1:0]) 
            2'b01: begin
                tmp<=tmp+x_reg;
            end
            2'b10: begin
                tmp<=tmp+nx_reg;
            end 
        endcase        
        busy<=0;
    end
end
always @(negedge busy) begin
    if(!busy)  z<={tmp[16:0],y_reg[16:2]};
end 
endmodule
