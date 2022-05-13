#include "bits/stdc++.h"
using namespace std;

template <typename T, int NDIMS> struct tensor_view {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    T* data;

    tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T* data_) : shape(shape_), strides(strides_), data(data_) {}

public:
    tensor_view() : shape{0}, strides{0}, data(nullptr) {}

protected:
    int flatten_index(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) { res += idx[i] * strides[i]; }
        return res;
    }
    int flatten_index_checked(std::array<int, NDIMS> idx) const {
        int res = 0;
        for (int i = 0; i < NDIMS; i++) {
            assert(0 <= idx[i] && idx[i] < shape[i]);
            res += idx[i] * strides[i];
        }
        return res;
    }

public:
    T& operator[] (std::array<int, NDIMS> idx) const {
        return data[flatten_index(idx)];
    }
    T& at(std::array<int, NDIMS> idx) const {
        return data[flatten_index_checked(idx)];
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type operator[] (int idx) const {
        std::array<int, NDIMS-1> nshape; std::copy(shape.begin()+1, shape.end(), nshape.begin());
        std::array<int, NDIMS-1> nstrides; std::copy(strides.begin()+1, strides.end(), nstrides.begin());
        T* ndata = data + (strides[0] * idx);
        return tensor_view<T, NDIMS-1>(nshape, nstrides, ndata);
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type at(int idx) const {
        assert(0 <= idx && idx < shape[0]);
        return operator[](idx);
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 == D), T&>::type operator * () const {
        return *data;
    }

    template <typename U, int D> friend struct tensor_view;
    template <typename U, int D> friend struct tensor;
};

template <typename T, int NDIMS> struct tensor {
    static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
    std::array<int, NDIMS> shape;
    std::array<int, NDIMS> strides;
    int len;
    T* data;

public:
    tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

    explicit tensor(std::array<int, NDIMS> shape_, const T& t = T()) {
        shape = shape_;
        strides[NDIMS-1] = 1;
        for (int i = NDIMS-1; i > 0; i--) {
            strides[i-1] = strides[i] * shape[i];
        }
        len = strides[0] * shape[0];
        data = new T[len];
        std::fill(data, data + len, t);
    }

    tensor(const tensor& o) : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
        for (int i = 0; i < len; i++) {
            data[i] = o.data[i];
        }
    }

    tensor& operator=(tensor&& o) noexcept {
        using std::swap;
        swap(shape, o.shape);
        swap(strides, o.strides);
        swap(len, o.len);
        swap(data, o.data);
        return *this;
    }
    tensor(tensor&& o) : tensor() {
        *this = std::move(o);
    }
    tensor& operator=(const tensor& o) {
        return *this = tensor(o);
    }
    ~tensor() { delete[] data; }

    using view_t = tensor_view<T, NDIMS>;
    view_t view() {
        return tensor_view<T, NDIMS>(shape, strides, data);
    }
    operator view_t() {
        return view();
    }

    using const_view_t = tensor_view<const T, NDIMS>;
    const_view_t view() const {
        return tensor_view<const T, NDIMS>(shape, strides, data);
    }
    operator const_view_t() const {
        return view();
    }

    T& operator[] (std::array<int, NDIMS> idx) { return view()[idx]; }
    T& at(std::array<int, NDIMS> idx) { return view().at(idx); }
    const T& operator[] (std::array<int, NDIMS> idx) const { return view()[idx]; }
    const T& at(std::array<int, NDIMS> idx) const { return view().at(idx); }

    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type operator[] (int idx) {
        return view()[idx];
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<T, NDIMS-1>>::type at(int idx) {
        return view().at(idx);
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<const T, NDIMS-1>>::type operator[] (int idx) const {
        return view()[idx];
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 < D), tensor_view<const T, NDIMS-1>>::type at(int idx) const {
        return view().at(idx);
    }

    template <int D = NDIMS>
    typename std::enable_if<(0 == D), T&>::type operator * () {
        return *view();
    }
    template <int D = NDIMS>
    typename std::enable_if<(0 == D), const T&>::type operator * () const {
        return *view();
    }
};

constexpr int dx[4] {1, -1, 0,  0};
constexpr int dy[4] {0,  0, 1, -1};

constexpr int inf = int(2e9);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin >> T;
    while(T--){

        int R, C;cin >> R >> C;

        tensor<char, 2> A({R, C});
        tensor<int64_t, 2> dist({R, C}, inf);         

        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                cin >> A[{i, j}];
            }
        }

        deque<array<int, 2>> Q;
        Q.push_back({0, 0});
        dist[{0, 0}] = 0;

        while(!Q.empty()){

            auto [x, y] = Q.front();
            Q.pop_front();

            for(int d = 0; d < 4; ++d){
                
                int nx = x + dx[d];
                int ny = y + dy[d];
                int nd = bool(A[{x, y}] != A[{nx, ny}]);

                if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                    if(dist[{nx, ny}] > dist[{x, y}] + nd){
                        dist[{nx, ny}] = dist[{x, y}] + nd;
                        if(nd)Q.push_back({nx, ny});
                        else Q.push_front({nx, ny});
                    }
                }

            } 

        }

        cout << dist[{R-1, C-1}] << '\n';

    }
    return 0;
}

