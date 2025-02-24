import pandas as pd
import matplotlib.pyplot as plt

# NPC 파일 리스트
npc_files = ["./npc_list1.csv"]
npc_colors = ["blue", "red", "green"]  # 각 차량별 색상 지정

# Line 파일 리스트
line_files = ["./Line1.csv", "./Line2.csv", "./Line3.csv"]
line_colors = ["green", "green", "green"]  # Line 경로 색상 지정

# 그래프 초기화
plt.figure(figsize=(10, 6))

# 📌 NPC 데이터 플로팅
for i, file in enumerate(npc_files):
    try:
        # 쉼표 구분 CSV 파일 읽기
        df = pd.read_csv(file)

        # 컬럼 이름 공백 제거
        df.columns = df.columns.str.strip()

        print(f"✅ {file} 컬럼 목록:", df.columns.tolist())

        # 중복된 좌표 제거
        df = df.drop_duplicates(subset=["East", "North"])

        # NPC 이동 경로 플로팅 (선 + 마커, 굵기 1.2)
        plt.plot(df["East"], df["North"], marker="o", ms=0.5, color=npc_colors[i], label=f"NPC {i+1}")

    except FileNotFoundError:
        print(f"❌ 파일을 찾을 수 없습니다: {file}")
    except KeyError as e:
        print(f"❌ 컬럼 '{e}'이(가) 없습니다. CSV 헤더를 확인하세요: {file}")
    except Exception as e:
        print(f"❌ 파일 {file}을 처리하는 중 오류 발생: {e}")

# 📌 Line 데이터 플로팅 (얇은 점선, linewidth=0.8)
for i, file in enumerate(line_files):
    try:
        # 공백 구분 CSV 파일 읽기 (헤더 없음)
        df = pd.read_csv(file, delim_whitespace=True, header=None, names=["East", "North", "Extra"])

        # 필요 없는 "Extra" 컬럼 제거
        df = df[["East", "North"]]

        print(f"✅ {file} 컬럼 목록:", df.columns.tolist())

        # Line 데이터는 점선으로 플로팅 (얇은 선)
        plt.plot(df["East"], df["North"], linestyle="-", linewidth=1.0, color=line_colors[i], label=f"Line {i+1}")

    except FileNotFoundError:
        print(f"❌ 파일을 찾을 수 없습니다: {file}")
    except KeyError as e:
        print(f"❌ 컬럼 '{e}'이(가) 없습니다. CSV 헤더를 확인하세요: {file}")
    except Exception as e:
        print(f"❌ 파일 {file}을 처리하는 중 오류 발생: {e}")

# 그래프 스타일 설정
plt.xlabel("East Position")
plt.ylabel("North Position")
plt.title("NPC Vehicle Paths & Reference Lines")
plt.legend()
plt.grid(True)

# 그래프 출력
plt.show()
