import cv2
import heapq
from collections import Counter

class HuffmanNode:
    def __init__(self, symbol, freq):
        self.symbol = symbol
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(freq_map):
    heap = []

    for symbol, freq in freq_map.items():
        node = HuffmanNode(symbol, freq)
        heapq.heappush(heap, node)

    while len(heap) > 1:
        left_node = heapq.heappop(heap)
        right_node = heapq.heappop(heap)

        merged_node = HuffmanNode(None, left_node.freq + right_node.freq)
        merged_node.left = left_node
        merged_node.right = right_node

        heapq.heappush(heap, merged_node)

    return heap[0]

def generate_huffman_codes(node, curr_node, huffman_codes):
    if node is None:
        return

    if node.symbol is not None:
        huffman_codes[node.symbol] = curr_node
        return

    generate_huffman_codes(node.left, curr_node + "0", huffman_codes)
    generate_huffman_codes(node.right, curr_node + "1", huffman_codes)

#take image input
image_path = "sample2.png"
img = cv2.imread(image_path, 0)

if img is None:
    print("Error: Can't read img, check image path.")
else:
    pixel_values = img.flatten().tolist()

    # Frequency of each gray level
    freq_map = Counter(pixel_values)

    #Build tree and code
    root = build_huffman_tree(freq_map)
    huffman_codes = {}
    generate_huffman_codes(root, "", huffman_codes)

    encoded_list = []
    for pixel in pixel_values:
        encoded_list.append(huffman_codes[pixel])

    encoded_bits = ''.join(encoded_list)

    original_bits = len(pixel_values) * 8
    compressed_bits = len(encoded_bits)
    compression_ratio = original_bits / compressed_bits

    print("\nHuffman Coding Compression")
    print("-----------------------------")
    print("Original size (bits):", original_bits)
    print("Compressed size (bits):", compressed_bits)
    print(f"Compression ratio: {compression_ratio:.3f}")
    print("\n  -By Krishna Aryal")