LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_SIGNED.ALL;

ENTITY control IS
PORT( Opcode : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
      RegDst : OUT STD_LOGIC;
      ALUSrc : OUT STD_LOGIC;
      MemToReg : OUT STD_LOGIC;
      RegWrite : OUT STD_LOGIC;
      MemRead : OUT STD_LOGIC;
      MemWrite : OUT STD_LOGIC;
      Branch : OUT STD_LOGIC;
      ALUOp : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      clock, reset : IN STD_LOGIC );
END control;

ARCHITECTURE behavior OF control IS
SIGNAL R_format, Lw, Sw, Beq, J : STD_LOGIC;
BEGIN
    -- Code to generate control signals using opcode bits
    R_format <= '1' WHEN Opcode="000000" ELSE '0';
    LW       <= '1' WHEN Opcode="100011" ELSE '0';
    SW       <= '1' WHEN Opcode="101011" ELSE '0';
    Beq      <= '1' WHEN Opcode="000100" ELSE '0';
    J        <= '1' WHEN Opcode="000010" ELSE '0';

    RegDst   <= R_format;
    ALUSrc   <= (R_format OR Lw OR Sw);
    MemToReg <= Lw;
    RegWrite <= R_format OR Lw;
    MemRead  <= Lw;
    MemWrite <= Sw;
    Branch   <= Beq OR J;
    ALUOp(1) <= R_format;
    ALUOp(0) <= Beq OR J;

END behavior;
